#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


int main() {
	double radius = 0.0;
	{
		std::cout << "Welcome! Set the radius for a sphere " << std::endl;
		std::cin >> radius;

		std::cout << "The volume is: " << (4.0 / 3.0) * M_PI * pow(radius, 3.0) << std::endl;

		std::cout << "The area is: " << 4.0 * M_PI * pow(radius, 2.0) << std::endl;
	}

	//Windows specific
	system("pause");




	return 0;
}
