#pragma once
#include <iostream>
#include <unordered_map>
#include "Vertex.h"

class Graph
{
public: 
	Graph(std::istream& is);

public:
	void addVertex(std::string vertexName);
	void addAdjacentVertexForSpecificVertex(std::string adjacentVertex, std::string vertexName);
private:
	void readInput(std::istream& is);
	int readNumberOfVertices(std::istream& is);
	void readLine(std::istream& is);
private:
	std::unordered_map<std::string, Vertex> graph;
};