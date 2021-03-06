
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int VALUE_VECTOR_MAX_SIZE = 5; //Max size of the vector
	vector<int> valueArray; //Vector containing all values
	double average = 0; //Final average of 5 values

	for (int i = 0; i < VALUE_VECTOR_MAX_SIZE; i++) { //Ask the user to input a value 5 times
		int TempVal;
		cout << "Valeur " << i + 1 << " : "; 
		cin >> TempVal;
		cout << endl;
		valueArray.push_back(TempVal); //Add the value to the vector
	}

	for (auto& value_i : valueArray) { //For each value int he vector add it to the average variable
		average += value_i;
	}
	average = average / VALUE_VECTOR_MAX_SIZE; //Devide the average variable by the vector size 

	cout << "Average of all 5 values = " << average << endl;

	system("pause");
}
