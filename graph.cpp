#include "graph.h"
#include<iterator>
#include<iostream>
using namespace std;

graph::graph(int v)
{
	adj = new vector<int>[v];
	color = new int[v];
	color[0] = 0;
	available = new bool[v];
}

void graph::addEdge(int v1, int v2) {
  
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);

}

void graph::greedyColoring(int v)
{
	
	for (int u = 1; u < v; u++) {
		color[u] = -1;   
	}
	

	for (int cr = 0; cr < v; cr++)
		available[cr] = false;

	
	for (int u = 1; u < v; u++)
	{

		//puts("==========================================");
		//// Process all adjacent vertices and flag their colors 
		//// as unavailable 

		vector<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			if (color[*i] != -1)
				available[color[*i]] = true;
			
		}
		
		 
		int cr;
		for (cr = 0; cr < v; cr++)
			if (available[cr] == false)
				break;

		color[u] = cr;
		
		
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (color[*i] != -1)
				available[color[*i]] = false;

	}

	
	/*for (int u = 0; u < v; u++) {
		cout << "Vertex " << u << " --->  Color "
			<< color[u] << endl;
	}*/
}
graph::~graph()
{
	delete[] adj;
	delete[]color;
	delete[]available;
}
