#include "pch.h"

#include <iostream>

int vala = 4;
int valb = 3;

int *val_a = &vala;
int *val_b = &valb;

void swap(int a, int b)
{
	//This function swaps the values contained in the two pointers
	int* c = &a;


	*val_a = b;
	*val_b = *c;

}

void print_value(int a, int b)
{
	//This function shows the values and their pointer
	std::cout << "The value a is: " << a << " and is contained in address: " << &a << std::endl;
	std::cout << "The value b is: " << b << " and is contained in address: " << &b << std::endl;
}

int main(const char* argv, int argc)
{


	print_value(*val_a, *val_b);

	swap(*val_a, *val_b);

	print_value(*val_a, *val_b);

	//Windows specific
	system("pause");
	return 0;
}
