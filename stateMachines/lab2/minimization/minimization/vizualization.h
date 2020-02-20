#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

#include <boost/graph/graphviz.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/iteration_macros.hpp>

using namespace std;

struct MooreMachine
{
	vector<int> inputs; 
	vector<string> outputs;
	vector<vector<int>> graph; 
};

struct MealyMachine
{
	vector<vector<string>> graph;
	vector<string> states;
};

struct VertexProps
{
	string label;
};

struct EdgeProps
{
	string label;
};

using Graph = boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, VertexProps, EdgeProps>;

void CreateMooreGraph(MooreMachine& mooreMachine, map<string, string> &automatStates)
{
	Graph graph;
	vector<Graph::vertex_descriptor> vertices;
	map<string, string>::iterator it = automatStates.begin();
	for (size_t i = 0; i < mooreMachine.graph[0].size(); ++i)
	{
		string vertexLabel = 'q' + to_string(mooreMachine.inputs.at(i)) + mooreMachine.outputs[i];
		map<string, string>::iterator it = automatStates.find(vertexLabel);
		//vertexLabel += '-' + it->second;
		vertexLabel = it->second + (mooreMachine.outputs[i]);
		vertices.push_back(boost::add_vertex({ vertexLabel }, graph));
	}

	for (size_t i = 0; i < mooreMachine.graph.size(); ++i)
	{
		for (size_t j = 0; j < mooreMachine.graph[0].size(); ++j)
		{
			string edgeLabel = 'x' + to_string(i + 1);
			boost::add_edge(vertices[j], vertices[mooreMachine.graph[i][j]], { edgeLabel }, graph);
		}
	}

	boost::dynamic_properties dp;
	dp.property("label", boost::get(&VertexProps::label, graph));
	dp.property("label", boost::get(&EdgeProps::label, graph));
	dp.property("node_id", boost::get(boost::vertex_index, graph));
	ofstream ofs("moore.dot");
	boost::write_graphviz_dp(ofs, graph, dp);

}

void CreateMealyGraph(MealyMachine& mealyMachine, map<string, string> &automatStates)
{
	Graph graph;
	vector<Graph::vertex_descriptor> vertices;
	map<string, string>::iterator it = automatStates.begin();
	for (size_t i = 0; i < mealyMachine.graph[0].size(); ++i)
	{
		string vertexLabel = "q" + to_string(i);// +mooreMachine.outputs[i];
		map<string, string>::iterator it = automatStates.find(vertexLabel);
		vertices.push_back(boost::add_vertex({ vertexLabel }, graph));
	}

	for (size_t i = 0; i < mealyMachine.graph.size(); ++i)
	{
		for (size_t j = 0; j < mealyMachine.graph[0].size(); ++j)
		{
			string edgeLabel = 'x' + to_string(i + 1) + "/" + mealyMachine.graph[i][j].substr(2, 3);
			boost::add_edge(vertices[j], vertices[stoi(mealyMachine.graph[i][j].substr(1, 1))], { edgeLabel }, graph);
		}
	}

	boost::dynamic_properties dp;
	dp.property("label", boost::get(&VertexProps::label, graph));
	dp.property("label", boost::get(&EdgeProps::label, graph));
	dp.property("node_id", boost::get(boost::vertex_index, graph));
	ofstream ofs("mealy.dot");
	boost::write_graphviz_dp(ofs, graph, dp);
}