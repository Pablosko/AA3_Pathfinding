#include "Greedy.h"
#include "utils.h"
Greedy::Greedy()
{
}
Path Greedy::CalculatePath(Graph* graph, Vector2D from, Vector2D to)
{
	const float minCostSoFarFlag = 99999;
	std::map<Vector2D,int> pathfindings;
	int maxCount = 500;
	int count = 0;
	Path path = Path();
	Node* closestNode = GetClosestNodeToTarget(graph->GetNodeFromVector2D(from), to, pathfindings);
	do
	{
		Node* tempNode = GetClosestNodeToTarget(closestNode, to, pathfindings);
		if (closestNode == tempNode)
			break;
		closestNode = tempNode;
		pathfindings[closestNode->position] = 1;
		path.points.push_back(closestNode->position);
		count++;

	} while (closestNode->position != to && count < maxCount);

	return path;
}

Node* Greedy::GetClosestNodeToTarget(Node* node, Vector2D destination,std::map<Vector2D,int> path)
{
	const float lowestFlag = 1000000;
	Node* lowestCostNode = node;
	float lowestDistance = lowestFlag;
	for (auto connection : node->conections)
	{
		if (path.count(connection->to->position))
			continue;
		if (connection->to->position == destination)
			return connection->to;
		float distance = destination.Distance(connection->to->position, destination);
		if (distance < lowestDistance)
		{
			lowestCostNode = connection->to;
			lowestDistance = distance;
		}
	}
	return lowestCostNode;
}
