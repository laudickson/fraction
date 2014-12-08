//fraction.h

#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class fraction 
{
	public:
		//values
		fraction(int num = 0, int den=  1);
		
		fraction & redux();
		fraction getredux();
		
		//operations
		fraction operator + (const fraction &f);
		fraction operator - (const fraction &f);
		fraction operator * (const fraction &f);
		fraction operator / (const fraction &f);
		
		//equality/inequality, greater/less than
		bool operator == (const fraction &f);
		bool operator != (const fraction &f);
		bool operator <= (const fraction &f);
		bool operator >= (const fraction &f);
		bool operator < (const fraction &f);
		bool operator > (const fraction &f);
		
		//display features
		friend ostream & operator << (ostream &output, const fraction &f); //found this cool trick on someone's repo
		void display();
		string maketext();
		
	private:
		int num;
		int den;
		int getgcd(int a, int b);
}

#endif
