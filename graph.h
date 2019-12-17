#pragma once
#include<vector>
#include<iostream>
#include<iterator>
using namespace std;

class graph
{
	int v;    
	vector<int> *adj; 
	int * color;
	bool *available;
	
public:
	graph(int v);
	void addEdge(int v1, int v2);
	void greedyColoring(int v);
	~graph();
};

