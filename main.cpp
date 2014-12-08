//Dickson Lau | December 2014
//main.cpp (testing for fractions)

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "fraction.h"

using namespace std;

int main()
{	
	//generate random numbers
	srand(time(NULL));
	
	fraction a(rand()% 10 + 1, rand() % 10 + 1);
	fraction b(rand()% 10 + 1, rand() % 10 + 1);
	
	cout << "fraction 1= " << a << ", fraction 2 = " << b << endl;
	
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
	
	cout << "fraction 1 == fraction 2 ? " << (a == b) << endl;
	cout << "fraction 1 != fraction 2 ? " << (a != b) << endl;
	cout << "fraction 1 <= fraction 2 ? " << (a <= b) << endl;
	cout << "fraction 1 >= fraction 2 ? " << (a >= b) << endl;
	cout << "fraction 1 < fraction 2 ? " << (a < b) << endl;
	cout << "fraction 1 > fraction 2 ? " << (a > b) << endl;
	
	return 0;
}
