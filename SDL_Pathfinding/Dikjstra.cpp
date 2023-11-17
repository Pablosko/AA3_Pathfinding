#include "Dikjstra.h"
#include <utility>      
#include <string>   
#include <map>   
#include <iostream> 
Dikjstra::Dikjstra()
{
}

Path Dikjstra::CalculatePath(Graph* graph, Vector2D from, Vector2D to)
{
	std::vector<Vector2D> pathfindings;
	std::map<Vector2D, int> costSoFar;
	std::map<Vector2D, Connection*> bestConnection;

	Node* node = graph->GetNodeFromVector2D(from);

	std::vector<Connection*> connectionsToCheck = node->conections;

	bool checking = true ;
	while (checking)
	{
		std::vector<Connection*> newConnections;

		for (auto connection : connectionsToCheck)
		{
		
			int cost = connection->cost + costSoFar[connection->from->position];
			if (costSoFar.count(connection->to->position)) 
			{
				if (cost < costSoFar[connection->to->position])
				{
					costSoFar[connection->to->position] = cost;
					bestConnection[connection->to->position] = connection;
				}
			}
			else 
			{
				for (auto c : connection->to->conections)
				{
					newConnections.push_back(c);
				}
				costSoFar[connection->to->position] = cost;
				bestConnection[connection->to->position] = connection;

				if (connection->to->position == to)
					checking = false;
			}
		}
		if (connectionsToCheck.size() == 0)
			return Path();
		connectionsToCheck = newConnections;
	}

	Vector2D checkingPos = to;
	Path path = Path();
	while (checkingPos != from)
	{
		path.points.push_back(bestConnection[checkingPos]->from->position);
		checkingPos = bestConnection[checkingPos]->from->position;
	}
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
