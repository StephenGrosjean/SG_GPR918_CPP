
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

const int VECTOR_NUMBER_SIZE = 10; //max size of the vector
vector<int> numbers; //vector containing all numbers
int maxNumber = 0;
int minNumber = 0;

int MaxValue(vector<int> Vector) {

	maxNumber = numbers[0]; //Set the max Number to the first term of the vector array

	//Check for each number in the vector if the term is superior than the last term 
	for (int i = 0; i < VECTOR_NUMBER_SIZE; i++) {
		
		//if it is superior then it became the new max number
		if (numbers[i] > maxNumber) {
			maxNumber = numbers[i];
		}
	}

	return maxNumber; //return the max number to the int 
}


int MinValue(vector<int> Vector) {
	minNumber = numbers[0]; //Set the minimum number to the first term fo the vector array

	//Check for each number in the vector if the term is inferior than the last term 
	for (int i = 0; i < VECTOR_NUMBER_SIZE; i++) {

		//if it is inferior then it became the new min number
		if (numbers[i] < minNumber) {
			minNumber = numbers[i];
		}
	}

	return minNumber; //return the min number to the int

}
int main(){

	//Ask the numbers
	for (int i = 0; i < VECTOR_NUMBER_SIZE; i++) {
		int tmpNumber = 0;
		cout << "Number " << i + 1 << " : ";
		cin >> tmpNumber;
		numbers.push_back(tmpNumber); //Add the numbers to the vector
	}

	cout << "Max : " << MaxValue(numbers) << endl; //Output the max value by calling MaxValue with the argument vector (numbers)
	cout << "Min : " << MinValue(numbers) << endl; //Output the min value by calling MaxValue with the argument vector (numbers)
	system("pause");
}