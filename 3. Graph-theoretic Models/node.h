#include <string>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
	public:
		Node();
		Node(string name);

		string getName();
		void print();
	private:
		string name;
};

#endif