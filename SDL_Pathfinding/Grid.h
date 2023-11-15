#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Vector2D.h"
#include <time.h>

class Grid
{
	friend class Graph;

public:
	Grid(char* filename);
	~Grid();

private:
	int num_cell_x;
	int num_cell_y;


public:
	std::vector<std::vector<int>>terrain;
	Graph* graph;
	Vector2D cell2pix(Vector2D cell);
	Vector2D pix2cell(Vector2D pix);
	Vector2D cell2pixNoOffset(Vector2D cell);
	bool isValidCell(Vector2D cell);
	int getNumCellX();
	int getNumCellY();
};
