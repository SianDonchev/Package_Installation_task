#pragma once
#include <string>
#include <vector>
#include <exception>

class Vertex
{
public:
	Vertex();
	Vertex(const std::string& vertexName);

public:
	const std::vector<std::string>& getAdjacentVertices()const { return adjacentVertices; }
	void addAdjacentVertex(const std::string& adjacentVertex);
	void markAsDiscovered() { vertexState = VertexState::discovered; }
	void markAsExplored() { vertexState = VertexState::explored; }
	bool isUnexplored()const { return vertexState == VertexState::unexplored; }
	bool isDiscovered()const { return vertexState == VertexState::discovered; }
	bool isExplored()const { return vertexState == VertexState::explored; }

private:
	std::string name;
	std::vector<std::string> adjacentVertices;

	enum class VertexState
	{
		unexplored,
		discovered,
		explored
	};

	VertexState vertexState;
	
};