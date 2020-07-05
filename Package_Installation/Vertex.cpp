#include "Vertex.h"

Vertex::Vertex() : name(), adjacentVertices(), visited(false) {}

Vertex::Vertex(const std::string& vertexName) : name(vertexName), adjacentVertices(), visited(false) {}

void Vertex::addAdjacentVertex(const std::string& adjacentVertex)
{
	adjacentVertices.push_back(adjacentVertex);
}
