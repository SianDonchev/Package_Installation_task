#pragma once
#include <iostream>
#include <string>
#include "Graph.h"

class Graph;

Graph buildGraphFromInput(std::istream& is);
int readNumberOfVertices(std::istream& is);
void readLine(std::istream& is,Graph& g);