#include "Vertex.h"

Vertex::Vertex() : name(), adjacentVertices(), vertexState(VertexState::unexplored) {}

Vertex::Vertex(const std::string& vertexName) : name(vertexName), adjacentVertices(), vertexState(VertexState::unexplored) {}

void Vertex::addAdjacentVertex(const std::string& adjacentVertex)
{
	adjacentVertices.push_back(adjacentVertex);
}
