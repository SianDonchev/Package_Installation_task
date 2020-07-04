#include "Vertex.h"

Vertex::Vertex(): name(), adjacentVertices(){}

Vertex::Vertex(std::string vertexName): name(vertexName), adjacentVertices(){}

void Vertex::addAdjacentVertex(std::string adjacentVertex)
{
	adjacentVertices.push_back(adjacentVertex);
}
