#include <iostream>
#include <algorithm> 
#include <vector>
#include "Food.h"
using namespace std;

typedef vector<Food> Menu;

Menu greedy(Menu foods, int maxCal, bool (*keyFunction)(Food, Food));
void testGreedy(Menu foods, int maxCal, bool (*keyFunction)(Food, Food));

//Function that defines whats a Better food
bool BestFood(Food a, Food b){
	return a.getVal() > b.getVal();
}

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

	testGreedy(menu, 800, BestFood);

	return 0;
}

Menu greedy(Menu foods, int maxCal, bool (*keyFunction)(Food, Food)){
	Menu sorted = foods;
	sort(sorted.begin(), sorted.end(), keyFunction);
	Menu result;

	int totalCal = 0;

	for(auto food : sorted){
		if(totalCal + food.getCal() < maxCal){
			result.push_back(food);
			totalCal += food.getCal();
		}
	}

	return result;
}

void testGreedy(Menu foods, int maxCal, bool (*keyFunction)(Food, Food)){
	Menu result = greedy(foods, maxCal, keyFunction);

	int totalCal = 0, totalVal = 0;

	for(auto food : result){
		totalCal += food.getCal();
		totalVal += food.getVal();
	}

	cout << "Total Calories: " << totalCal << "\n";
	cout << "Total Value: " << totalVal << "\n";

	for(auto food : result){
		cout << "\t";
		food.print();
		cout << "\n";
	}

}