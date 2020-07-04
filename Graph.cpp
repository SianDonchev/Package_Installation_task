#include "Graph.h"

Graph::Graph(std::istream& is)
{
	readInput(is);
}

void Graph::addVertex(std::string vertexName)
{
	Vertex vertex(vertexName);
	graph.insert({ vertexName,vertex });

	allVertices.insert(vertexName);
}

void Graph::addAdjacentVertexForSpecificVertex(std::string adjacentVertex, std::string vertexName)
{
	graph[vertexName].addAdjacentVertex(adjacentVertex);
}

void Graph::DFS()
{
	for(const std::string& vertexName : allVertices)
	{
		if (!graph[vertexName].isVisited())
		{
			DFS_VISIT(vertexName);
		}
	}
}

void Graph::DFS_VISIT(std::string vertexName)
{
	std::vector<std::string> adjacentVertices = getAdjacentVerticesForASpecificVertex(vertexName);

	for (std::string adjacentVertex : adjacentVertices)
	{
		if (!graph[adjacentVertex].isVisited())
		{
			DFS_VISIT(adjacentVertex);
		}
	}
	graph[vertexName].markAsVisited();
	topologicallySorted.push_front(vertexName);
}

std::list<std::string> Graph::topologicalSort()
{
	emptyingTopologicallySortedVertices();

	DFS();
	topologicallySorted.reverse();
	
	return topologicallySorted;
}

const std::vector<std::string>& Graph::getAdjacentVerticesForASpecificVertex(std::string vertexName)
{
	return graph[vertexName].getAdjacentVertices();
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
	std::string numOfVertices;
	is >> numOfVertices;

	if (!isNumber(numOfVertices))
	{
		throw std::logic_error("You have entered an invalid input");
	}

	return std::stoi(numOfVertices);
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

void Graph::emptyingTopologicallySortedVertices()
{
	topologicallySorted = std::list<std::string>();
}
