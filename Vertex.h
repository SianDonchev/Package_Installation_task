#pragma once
#include <string>
#include <vector>

class Vertex
{
public:
	Vertex();
	Vertex(std::string vertexName);

public:
	void addAdjacentVertex(std::string adjacentVertex);

private:
	std::string name;
	std::vector<std::string> adjacentVertices;
	
};