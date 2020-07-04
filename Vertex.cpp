#include "Vertex.h"

Vertex::Vertex() : name(), adjacentVertices(), visited(false) {}

Vertex::Vertex(std::string vertexName) : name(vertexName), adjacentVertices(), visited(false) {}

void Vertex::addAdjacentVertex(std::string adjacentVertex)
{
	adjacentVertices.push_back(adjacentVertex);
}
