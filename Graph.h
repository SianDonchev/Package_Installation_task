#pragma once
#include <iostream>
#include <unordered_map>
#include<unordered_set>
#include <list>
#include "Vertex.h"
#include "ValidationFunctionsForTheInput.h"

const int FIRST_POSITION = 0;

class Graph
{
public: 
	Graph(std::istream& is);

public:
	void addVertex(std::string vertexName);
	void addAdjacentVertexForSpecificVertex(std::string adjacentVertex, std::string vertexName);
	void DFS();
	void DFS_VISIT(std::string vertexName);
	std::list<std::string> topologicalSort();
	const std::vector<std::string>& getAdjacentVerticesForASpecificVertex(std::string vertexName);

private:
	void readInput(std::istream& is);
	int readNumberOfVertices(std::istream& is);
	void readLine(std::istream& is);
	void emptyingTopologicallySortedVertices();

private:
	std::unordered_map<std::string, Vertex> graph;
	std::unordered_set<std::string> allVertices;
	std::list<std::string> topologicallySorted;
};