#include <vector>
#include <tuple>
#include "node.h"
#include "edge.h"
using namespace std;

#ifndef DIGRAPH_H
#define DIGRAPH_H

class Digraph {
	public:
		Digraph();

		void addNode(Node);
		void addEdge(Edge);

		Node getNode(string);

		void print();

	private:
		//This is a vector which contains a node source and a vector of node destinations
		vector< tuple< Node, vector<Node>>> nodes;
};

#endif