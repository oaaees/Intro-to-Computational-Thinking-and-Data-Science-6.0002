#include <string>
using namespace std;

#ifndef FOOD_H
#define FOOD_H

class Food {
	public:
		Food(int cal, int value, string name);

		int getCal();
		int getVal();
		string getName();
	
		void print();

		~Food();
	private:
		int cal;
		int val;
		string name;
};

#endif