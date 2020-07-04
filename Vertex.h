#pragma once
#include <string>
#include <vector>

class Vertex
{
public:
	Vertex();
	Vertex(std::string vertexName);

public:
	const std::vector<std::string>& getAdjacentVertices()const { return adjacentVertices; }
	void addAdjacentVertex(std::string adjacentVertex);
	void markAsVisited() { visited = true; }
	bool isVisited()const { return visited == true; }
private:
	std::string name;
	std::vector<std::string> adjacentVertices;
	bool visited;
	
};