	#pragma once
#include "Graph.h"
#include "Path.h"
class PathFindingAlgorithm
{
public:
	PathFindingAlgorithm();
	virtual Path CalculatePath(Graph* graph, Vector2D from, Vector2D to) = 0;
};

