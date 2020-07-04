#pragma once
#include "Graph.h"

inline void printList(const std::list<std::string> l)
{
	for (std::string s : l)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;
}

inline void packagesInstallationTask()
{
	std::cout << "1.Firstly, enter the number of lines you want to insert." << std::endl
		<< "2.Secondly, add the packages with the dependencies for each one." << std::endl;

	Graph packages(std::cin);

	std::cout << "One possible order to install the packages is: ";
	printList(packages.topologicalSort());

}