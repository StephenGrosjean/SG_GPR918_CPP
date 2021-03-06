
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

const int VECTOR_NUMBER_SIZE = 10; //Max size of the vector array
vector<int> numbers; //Vector array containing all the numbers

int maxNumber = 0; //Max number int
int minNumber = 0; //Min number int

int& refMaxNumber = maxNumber; //Max number reference is set to the maxNumber int
int& refMinNumber = minNumber; //Min number reference is set to the minNumber int

int& MaxValue(vector<int> Vector) {

	refMaxNumber = numbers[0];  //Set the max Number to the first term of the vector array

	//Check for each number in the vector if the term is superior than the last term 
	for (int i = 0; i < VECTOR_NUMBER_SIZE; i++) {

		//if it is superior then it became the new max number
		if (numbers[i] > refMaxNumber) {
			refMaxNumber = numbers[i];
		}
	}

	//return the max number to the int 
	return refMaxNumber;
}


int& MinValue(vector<int> Vector) {
	refMinNumber = numbers[0];  //Set the min Number to the first term of the vector array

	//Check for each number in the vector if the term is superior than the last term 
	for (int i = 0; i < VECTOR_NUMBER_SIZE; i++) {

		//if it is superior then it became the new min number
		if (numbers[i] < refMinNumber) {
			refMinNumber = numbers[i];
		}
	}

	//return the max number to the int 
	return refMinNumber;

}

int main()
{
	//Ask for the numbers
	for (int i = 0; i < VECTOR_NUMBER_SIZE; i++) {
		int tmpNumber = 0;
		cout << "Number " << i + 1 << " : ";
		cin >> tmpNumber;
		numbers.push_back(tmpNumber); //Add the number to the vector
	}

	cout << "Max : " << MaxValue(numbers) << endl; //Output the max value by calling MaxValue with the argument vector (numbers)
	cout << "Min : " << MinValue(numbers) << endl; //Output the min value by calling MaxValue with the argument vector (numbers)
	system("pause");

}

