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
	vector<vector<string>> graph; 
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

void CreateMooreGraph(MooreMachine& mooreMachine)
{
	Graph graph;
	vector<Graph::vertex_descriptor> vertices;
	for (size_t i = 0; i < mooreMachine.graph.size(); i++)
	{
		string vertexLabel = "A" + to_string(i) + mooreMachine.graph.at(i).at(1);
		vertices.push_back(boost::add_vertex({ vertexLabel }, graph));
	}
	vertices;
	for (size_t i = 0; i < mooreMachine.graph.size(); i++)
	{
		for (size_t j = 2; j < mooreMachine.graph.at(0).size(); j++)
		{
			string edgeLabel = 'x' + to_string(j - 1);
			boost::add_edge(vertices[i], vertices[stoi(mooreMachine.graph[i][j].substr(1, 1))], { edgeLabel }, graph);
		}
	}

	boost::dynamic_properties dp;
	dp.property("label", boost::get(&VertexProps::label, graph));
	dp.property("label", boost::get(&EdgeProps::label, graph));
	dp.property("node_id", boost::get(boost::vertex_index, graph));
	ofstream ofs("moore.dot");
	boost::write_graphviz_dp(ofs, graph, dp);

}

void CreateMealyGraph(MealyMachine& mealyMachine)
{
	Graph graph;
	vector<Graph::vertex_descriptor> vertices;
	for (size_t i = 0; i < mealyMachine.graph[0].size() - 1; ++i)
	{
		string vertexLabel = "A" + to_string(i);// +mooreMachine.outputs[i];
		vertices.push_back(boost::add_vertex({ vertexLabel }, graph));
	}

	for (size_t i = 1; i < mealyMachine.graph[0].size(); i++)
	{
		for (size_t j = 0; j < mealyMachine.graph.size(); j++)
		{
			string edgeLabel = 'x' + to_string(i) + "/" + mealyMachine.graph[j][i].substr(2);
			boost::add_edge(vertices[j], vertices[stoi(mealyMachine.graph[j][i].substr(1, 1))], { edgeLabel }, graph);
		}
	}

	boost::dynamic_properties dp;
	dp.property("label", boost::get(&VertexProps::label, graph));
	dp.property("label", boost::get(&EdgeProps::label, graph));
	dp.property("node_id", boost::get(boost::vertex_index, graph));
	ofstream ofs("mealy.dot");
	boost::write_graphviz_dp(ofs, graph, dp);
}