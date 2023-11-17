#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "grid.h"
using namespace std;
struct Node 
{
	friend struct Connection;
	Node(Vector2D _p)
	{
		position = _p;
	}
	Vector2D position;
	vector<Connection*> conections;
};
struct Connection 
{
	friend struct Node;
	Connection(Node* _to,Node* _from)
	{
		to = _to;
		from = _from;
		cost = 1;
	}
	Connection(Node* _to, Node* _from,float _cost)
	{
		to = _to;
		from = _from;
		cost = _cost;
	}
	Node* from;
	Node* to;
	int cost = 0;
};
class Graph	
{
	friend class Grid;
public:
	Graph(Grid* grid);
	vector<Node*> nodes;
	Connection* CheckAndCreateConnection(Grid* grid, Node* from, int x, int y,float cost);
	Node* GetNodeFromTerrainIndex(Vector2D terrainIndex);
	Node* GetNodeFromVector2D(Vector2D position);
	void DebugGraphNode(int node);
};

