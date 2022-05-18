#include <iostream>
#include "node.h"
using namespace std;

Node::Node(){}

Node::Node(string _name){
	name = _name;
}

string Node::getName(){
	return name;
}

void Node::print(){
	cout << name;
}