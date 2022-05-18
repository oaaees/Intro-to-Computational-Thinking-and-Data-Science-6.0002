#include <iostream>
#include "edge.h"
using namespace std;

Edge::Edge(Node _src, Node _dest){
	src = _src;
	dest = _dest;
}

Node Edge::getSrc(){
	return src;
}

Node Edge::getDest(){
	return dest;
}

void Edge::print(){
	src.print();
	cout << " -> ";
	dest.print();
}