#include "Graph.h"

void Graph::addVertex(const std::string& vertexName)
{
	Vertex vertex(vertexName);
	graph.insert({ vertexName,vertex });

	allVertices.insert(vertexName);
}

void Graph::addDirectedEdge(const std::string& from, const std::string& to)
{
	graph[from].addAdjacentVertex(to);
}

void Graph::dfs()
{
	for(const std::string& vertexName : allVertices)
	{
		if (graph[vertexName].isUnexplored())
		{
			dfsVisit(vertexName);
		}

	}
}

void Graph::dfsVisit(const std::string& vertexName)
{
	std::vector<std::string> adjacentVertices = getAdjacentVerticesForASpecificVertex(vertexName);

	for (std::string adjacentVertex : adjacentVertices)
	{
		if (graph[adjacentVertex].isUnexplored())
		{
			graph[adjacentVertex].markAsDiscovered();
			dfsVisit(adjacentVertex);
		}
		else if (graph[adjacentVertex].isDiscovered())
		{
			throw std::logic_error("There is a cycle in the graph");
		}
	}
	graph[vertexName].markAsExplored();
	topologicallySorted.push_front(vertexName);
}

std::list<std::string> Graph::topologicalSort()
{
	emptyingTopologicallySortedVertices();

	dfs();
	topologicallySorted.reverse();
	
	return topologicallySorted;
}

const std::vector<std::string>& Graph::getAdjacentVerticesForASpecificVertex(const std::string& vertexName)
{
	return graph[vertexName].getAdjacentVertices();
}

void Graph::emptyingTopologicallySortedVertices()
{
	topologicallySorted = std::list<std::string>();
}
