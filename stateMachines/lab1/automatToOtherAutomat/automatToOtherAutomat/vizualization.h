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
	vector<string> outputs{ "y1", "y1", "y2", "y2", "y3" };
	vector<vector<int>> graph{
		{ 3, 0, 0, 2, 2 },
		{ 1, 4, 4, 0, 0 }
	};
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

void CreateMooreGraph(const MooreMachine& mooreMachine, const map<string, string> &automatStates)
{
	Graph graph;
	vector<Graph::vertex_descriptor> vertices;
	map<string, string>::iterator it;// = automatStates.begin();
	for (size_t i = 0; i < mooreMachine.graph[0].size(); ++i)
	{
		string vertexLabel = 'q' + to_string(i) + mooreMachine.outputs[i];
		map<string, string>::iterator it = automatStates.find(vertexLabel);
		vertexLabel += '-' + it->second;
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
	ofstream ofs("graph.dot");
	boost::write_graphviz_dp(ofs, graph, dp);
}