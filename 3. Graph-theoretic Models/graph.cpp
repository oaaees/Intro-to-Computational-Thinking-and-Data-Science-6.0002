#include <iostream>
#include "graph.h"
using namespace std;

void Graph::addEdge(Edge e){
	Edge rev(e.getDest(), e.getSrc());

	Digraph::addEdge(e);
	Digraph::addEdge(rev);

	return;
}