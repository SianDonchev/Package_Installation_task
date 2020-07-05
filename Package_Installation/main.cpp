#include "Graph.h"
#include "ReadGraphFromInput.h"

void printList(const std::list<std::string>& l)
{
	for (std::string s : l)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;
}

void packagesInstallationTask()
{

	std::cout << "1.Firstly, enter the number of lines you want to insert." << std::endl
		<< "2.Secondly, add the packages with the dependencies for each one." << std::endl;

	Graph packages = buildGraphFromInput(std::cin);
	
	std::cout << "One possible order to install the packages is: ";
	printList(packages.topologicalSort());

}

int main()
{
	try {
		packagesInstallationTask();
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what();
	}
	catch (std::logic_error& e)
	{
		std::cerr << "There is interdependent packages, so there is no possible solution.";
	}

	return 0;
}