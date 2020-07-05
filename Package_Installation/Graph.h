#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include "Vertex.h"

class Graph
{
public:
	void addVertex(const std::string& vertexName);
	void addDirectedEdge(const std::string& from, const std::string& to);
	std::list<std::string> topologicalSort();
	const std::vector<std::string>& getAdjacentVerticesForASpecificVertex(const std::string& vertexName);

private:
	void dfs();
	void dfsVisit(const std::string& vertexName);

	void emptyingTopologicallySortedVertices();

private:
	std::unordered_map<std::string, Vertex> graph;
	std::unordered_set<std::string> allVertices;
	std::list<std::string> topologicallySorted;
};