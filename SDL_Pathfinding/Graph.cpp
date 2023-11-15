#include "Graph.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "utils.h"

Graph::Graph(Grid* grid)
{
	//CreateAllNodes
	for (int y = 0; y < grid->terrain.size(); y++)
	{
		for (int x = 0; x < grid->terrain[y].size(); x++)
		{
			if (grid->terrain[y][x] != 0)
			{
				nodes.push_back(new Node(Vector2D(x * CELL_SIZE + 16, y * CELL_SIZE + 16)));
			}
		}
	}
	for (int y = 0; y < grid->terrain.size(); y++)
	{
		for (int x = 0; x < grid->terrain[y].size(); x++)
		{
			if (grid->terrain[y][x] != 0)
			{
				Node* node = GetNodeFromTerrainIndex(Vector2D(x, y));
				Connection* connection = CheckAndCreateConnection(grid, node, x + 1, y);
				if (connection != nullptr)
					node->conections.push_back(connection);
				connection = CheckAndCreateConnection(grid, node, x + 1, y + 1);
				if (connection != nullptr)
					node->conections.push_back(connection);
				connection = CheckAndCreateConnection(grid, node, x + 1, y - 1);
				if (connection != nullptr)
					node->conections.push_back(connection);
				connection = CheckAndCreateConnection(grid, node, x, y + 1);
				if (connection != nullptr)
					node->conections.push_back(connection);
				connection = CheckAndCreateConnection(grid, node, x, y - 1);
				if (connection != nullptr)
					node->conections.push_back(connection);
				connection = CheckAndCreateConnection(grid, node, x - 1, y);
				if (connection != nullptr)
					node->conections.push_back(connection);
				connection = CheckAndCreateConnection(grid, node, x - 1, y + 1);
				if (connection != nullptr)
					node->conections.push_back(connection);
				connection = CheckAndCreateConnection(grid, node, x - 1, y - 1);
				if (connection != nullptr)
					node->conections.push_back(connection);

			}
		}
	}
}

Connection* Graph::CheckAndCreateConnection(Grid* grid,Node* from,int x, int y)
{
	if (grid->isValidCell(Vector2D(x, y)))
		return new Connection(GetNodeFromTerrainIndex(Vector2D(x,y)),from);
	return nullptr;
}

Node* Graph::GetNodeFromTerrainIndex(Vector2D terrainIndex)
{
	int offset = CELL_SIZE / 2;
	terrainIndex = Vector2D(terrainIndex.x * CELL_SIZE + offset, terrainIndex.y * CELL_SIZE + offset);
	
	for (auto node : nodes) 
	{
		if (node->position ==  terrainIndex)
			return node;
	}
}

Node* Graph::GetNodeFromVector2D(Vector2D position)
{
	for (auto node : nodes)
	{
		if (node->position == position)
			return node;
	}
}

void Graph::DebugGraphNode(int node)
{

	if (node == -1)
	{
		for (auto nodee: nodes)
		{
			DrawPositionInMaze(nodee->position,255,255,0,255);
		}
		return;
	}
	DrawPositionInMaze(nodes[node]->position, 255, 255, 0, 255);

	for (auto connection : nodes[node]->conections)
	{
		DrawPositionInMaze(connection->to->position, 255/2, 255/2, 0, 255 / 2);
	}
}
