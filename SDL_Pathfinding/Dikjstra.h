#pragma once
#include "PathFindingAlgorithm.h"
class Dikjstra :  public PathFindingAlgorithm
{
public:
	Dikjstra();
	virtual Path CalculatePath(Graph* graph, Vector2D from, Vector2D to) override;
	Connection* GetLowestConnection(Connection* lasConnection, Vector2D destination);

	
};

