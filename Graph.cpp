#include "Graph.h"

Graph::Graph(std::istream& is)
{
	readInput(is);
}

void Graph::addVertex(std::string vertexName)
{
	Vertex vertex(vertexName);
	graph.insert({ vertexName,vertex });
}

void Graph::addAdjacentVertexForSpecificVertex(std::string adjacentVertex, std::string vertexName)
{
	graph[vertexName].addAdjacentVertex(adjacentVertex);
}

void Graph::readInput(std::istream& is)
{
	int numOfVertices = readNumberOfVertices(is);
	while (numOfVertices)
	{
		readLine(is);
		--numOfVertices;
	}
}

int Graph::readNumberOfVertices(std::istream& is)
{
	int numOfVertices;
	is >> numOfVertices;

	return numOfVertices;
}

void Graph::readLine(std::istream& is)
{
	std::string vertexName;
	std::string nameOfadjacentVertex;

	is >> vertexName;
	addVertex(vertexName);

	while (is.peek() != '\n')
	{
		is >> nameOfadjacentVertex;

		addVertex(nameOfadjacentVertex);
		addAdjacentVertexForSpecificVertex(nameOfadjacentVertex, vertexName);
	}
}
