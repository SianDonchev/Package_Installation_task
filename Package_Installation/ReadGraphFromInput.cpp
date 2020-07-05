#include "ReadGraphFromInput.h"

bool isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}


Graph buildGraphFromInput(std::istream& is)
{
	Graph g;

	int numOfVertices = readNumberOfVertices(is);
	while (numOfVertices)
	{
		readLine(is,g);
		--numOfVertices;
	}
	return g;
}

int readNumberOfVertices(std::istream& is)
{
	std::string numOfVertices;
	is >> numOfVertices;

	if (!isNumber(numOfVertices))
	{
		throw std::invalid_argument("You have entered an invalid input.");
	}

	return std::stoi(numOfVertices);
}

void readLine(std::istream& is, Graph& g)
{
	std::string vertexName;
	std::string nameOfAdjacentVertex;

	is >> vertexName;
	g.addVertex(vertexName);

	while (is.peek() != '\n')
	{
		is >> nameOfAdjacentVertex;

		g.addVertex(nameOfAdjacentVertex);
		g.addDirectedEdge(vertexName, nameOfAdjacentVertex);
	}
}
