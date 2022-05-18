#include "node.h"
using namespace std;

#ifndef EDGE_H
#define EDGE_H

class Edge {
	public:
		Edge(Node src, Node dest);

		Node getSrc();
		Node getDest();

		void print();
	private:
		Node src;
		Node dest;
};

#endif