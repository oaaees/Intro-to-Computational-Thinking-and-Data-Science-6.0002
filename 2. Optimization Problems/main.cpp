#include <iostream>
#include <algorithm> 
#include <vector>
#include "Food.h"
using namespace std;

typedef vector<Food> Menu;

Menu maxVal(Menu, int);
void testDecisionTree(Menu foods, int maxCal);

int main(){
	Menu menu;

	menu.push_back(Food(123, 89, "wine"));
	menu.push_back(Food(154, 90, "beer"));
	menu.push_back(Food(258, 95, "pizza"));
	menu.push_back(Food(354, 100, "burguer"));
	menu.push_back(Food(365, 90, "fries"));
	menu.push_back(Food(150, 79, "cola"));
	menu.push_back(Food(95 , 50, "apple"));
	menu.push_back(Food(195, 10, "donut"));

	testDecisionTree(menu, 750);

	return 0;
}

void testDecisionTree(Menu foods, int maxCal){
	Menu result = maxVal(foods, maxCal);

	int totalCal = 0, totalVal = 0;

	for(auto food: result){
		totalCal += food.getCal();
		totalVal += food.getVal();
	}

	cout << "Total Calories: " << totalCal << "\n";
	cout << "Total Value: " << totalVal << "\n";

	for(auto food: result){
		cout << "\t";
		food.print();
		cout << "\n";
	}

}

Menu maxVal(Menu foods, int avail){
	Menu result;

	if(foods.empty() || avail == 0){
		return result;
	} else if(foods.back().getCal() > avail){
		Menu nextMenu = foods;
		nextMenu.pop_back();

		result = maxVal(nextMenu, avail);
	} else {
		Food next = foods.back();

		Menu nextMenu = foods;
		nextMenu.pop_back();

		Menu taking = maxVal(nextMenu, avail - next.getCal());
		Menu notTaking = maxVal(nextMenu, avail);

		int valTaking = 0;
		int valNotTaking = 0;

		for(auto food : taking){
			valTaking += food.getVal();
		}

		for(auto food : notTaking){
			valNotTaking += food.getVal();
		}

		if(valTaking >= valNotTaking){
			taking.push_back(next);
			result = taking;
		} else {
			result = notTaking;
		}
	}

	return result;
}