#include "graph.h"
#include "digraph.h"
#include <string>
using namespace std;

Digraph buildCityGraph();

int main(){
	Digraph graph = buildCityGraph();

	graph.print();

	return 0;
}

Digraph buildCityGraph(){
	Digraph g;
	string cities[] = {"Boston", "Providence", "New York", "Chicago", "Denver", "Phoenix", "Los Angeles"};

	for(auto city : cities){
		g.addNode(Node(city));
	}

	g.addEdge(Edge(g.getNode("Boston"), g.getNode("Providence")));
	g.addEdge(Edge(g.getNode("Boston"), g.getNode("New York")));
	g.addEdge(Edge(g.getNode("Providence"), g.getNode("Boston")));
	g.addEdge(Edge(g.getNode("Providence"), g.getNode("New York")));
	g.addEdge(Edge(g.getNode("New York"), g.getNode("Chicago")));
	g.addEdge(Edge(g.getNode("Chicago"), g.getNode("Denver")));
	g.addEdge(Edge(g.getNode("Denver"), g.getNode("Phoenix")));
	g.addEdge(Edge(g.getNode("Denver"), g.getNode("New York")));
	g.addEdge(Edge(g.getNode("Los Angeles"), g.getNode("Boston")));

	return g;
}