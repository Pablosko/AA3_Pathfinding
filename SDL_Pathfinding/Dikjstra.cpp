#include "Dikjstra.h"

Dikjstra::Dikjstra()
{
}

Path Dikjstra::CalculatePath(Graph* graph, Vector2D from, Vector2D to)
{
	const float minCostSoFarFlag = 99999;
	std::vector<Vector2D> pathfindings;
	float costSoFar = 0; 
	float minCostSoFar = minCostSoFarFlag;
	Connection* lowestConnection = GetLowestConnection(graph->GetNodeFromVector2D(from)->conections[0],to);
	while (lowestConnection->from->position != to)
	{
		lowestConnection = GetLowestConnection(lowestConnection,to);
		pathfindings.push_back(lowestConnection->to->position);
		costSoFar++;
	}
	
	Path path = Path();
	path.points = pathfindings;

    return path;
}

Connection* Dikjstra::GetLowestConnection(Connection* lasConnection,Vector2D destination)
{
	const float lowestFlag = 1000;
	Connection* lowestCost = lasConnection;
	float lowestNumber = lowestFlag;
	for (auto connection : lasConnection->to->conections)
	{
		if (connection->to->position == destination)
			return connection;

		if ((connection->cost <= lowestNumber && connection->to->position != lasConnection->from->position)|| lowestNumber == lowestFlag)
		{
			lowestCost = connection;
			lowestNumber = connection->cost;
		}
	}
	return lowestCost;
}
