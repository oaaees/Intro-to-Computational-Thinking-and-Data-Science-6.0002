#include <iostream>
#include "Food.h"
using namespace std;

Food::Food(int _cal, int _val, string _name){
	cal = _cal;
	val = _val;
	name = _name;
}

int Food::getCal(){
	return cal;
}

int Food::getVal(){
	return val;
}

string Food::getName(){
	return name;
}

void Food::print(){
	cout << name << " cal: " << cal << " val: " << val;
}

Food::~Food(){}