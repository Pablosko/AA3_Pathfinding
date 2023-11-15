#pragma once
#include "PathFindingAlgorithm.h"
#include <utility>      
#include <string>   
#include <map>   
#include <iostream> 

using namespace std;
class Greedy : public PathFindingAlgorithm
{
public:
	Greedy();
	virtual Path CalculatePath(Graph* graph, Vector2D from, Vector2D to) override;
	Node* GetClosestNodeToTarget(Node* node, Vector2D destination, map<Vector2D, int> path);
};

