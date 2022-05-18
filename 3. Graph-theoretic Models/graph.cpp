#include <iostream>
#include "graph.h"
using namespace std;

Digraph::Digraph(){

}

void Digraph::addNode(Node n){
	for(auto node : nodes){
		if(get<0>(node).getName() == n.getName()){
			cout << "node " << get<0>(node).getName() << " already exists \n"; 
			return;
		}
	}

	vector<Node> destinations = {};
	nodes.push_back({n, destinations});
}

void Digraph::addEdge(Edge e){
	Node src = e.getSrc();
	Node dest = e.getDest();

	for(auto node : nodes){
		if(get<0>(node).getName() == src.getName()){
			get<1>(node).push_back(dest);
			cout << "added conection " << get<0>(node).getName() << " -> " << get<1>(node).back().getName() << " now "  << get<0>(node).getName() << " has " << get<1>(node).size() << " destinations" <<"\n";
			return;
		}
	}

	cout << "node " << src.getName() << " does not exist \n";
	return;
}

void Digraph::print(){
	for(auto node : nodes){
		get<0>(node).print();
		cout << " has " << get<1>(node).size() << " destinations";
		cout << "\n";
		for(auto destination : get<1>(node)){
			cout << "\t->";
			destination.print();
			cout << "\n";
		}
	}
}

