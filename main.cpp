#include "Graph.h"

int main()
{

	Graph g(std::cin);
	for (auto const& i : g.topologicalSort())
	{
		std::cout << i << " ";
	}

	return 0;
}