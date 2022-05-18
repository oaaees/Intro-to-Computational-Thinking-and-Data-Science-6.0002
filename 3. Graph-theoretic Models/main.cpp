#include "graph.h"
using namespace std;

int main(){
	Digraph graph;
	Node NY("NY");
	Node CHICAGO("Chicago");
	Edge road1(NY, CHICAGO);
	Edge road2(CHICAGO, NY);

	Node MERIDA("Merida");
	Node EJIDO("Ejido");
	Edge road3(MERIDA, EJIDO);
	Edge road4(MERIDA, NY);

	graph.addNode(NY);
	graph.addNode(CHICAGO);
	graph.addNode(MERIDA);
	graph.addNode(EJIDO);

	graph.addEdge(road1);
	graph.addEdge(road2);
	graph.addEdge(road3);
	graph.addEdge(road4);

	graph.print();

	return 0;
}