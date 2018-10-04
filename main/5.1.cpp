
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void fib(int n) {
	int first = 0;  //First int of the sequence
	int second = 1; //Second int of the sequence
	int third = 0;  //Third int of the sequence
	
	cout << "" << endl;

	for (int i = 0; i < n; i++) { //Generate the Fibonacci sequence
		third = first + second;
		first = second;
		second = third;

	}

	cout << n <<" term of the Fibonacci serie : " << first << endl; //Display only the last term calculated
	system("pause");
}

int main()
{
	
	int n = 0; //Define n as the fibonacci number we want to display
	cin >> n;
	fib(n); //Call the function fib with the parameter (n)


	
	
}

