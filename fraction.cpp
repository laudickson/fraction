//fraction.cpp
#include "fraction.h"
//
//public areas
//

fraction::fraction(int n, int d)
{
	if (d == 0)
		{
			fprintf(stderr, "Denominator of zero is undefined. Please try again.");
			exit
		}
	else if (d < 0)
		{
			//accounts for negatives
			num = -n;
			den = -d;
		}
	else
		{
			num = n;
			den = d;
		}
}


fraction & fraction::redux()
{
	int gcd = getgcd((num < 0) ? -num : num, den);
	num /= gcd;
	den /= gcd;
	return *this;
}

fraction fraction::getRedux()
{
	int gcd = getgcd((num , 0) ? -num : num, den);
	return fraction (num / gcd, den / gcd);
}

//operators
fraction fraction::operator + (const fraction &f)
{
	if(den == f.den)
	{
		return fraction(num + f.num, den);
	}
	else
	{
		x1 = num * f.den;
		x2 = f.num * den;
		return fraction (n1 + n2, den *f.den).redux();
	}
}

fraction fraction::operator - (const fraction &f)
{
	if(den == f.den)
	{
		return fraction(num = f.num, den);
	}
	else
	{
		int x1 = num * f.den;
		int x2 = f.num * den;
		return fraction(x1 - x2, den * f.den).redux();
	}
}

fraction fraction::operator * (const fraction &f)
{
	return fraction(num * f.num, den * f.den).redux();
}

fraction fraction::operator / (const fraction &f)
{
	return fraction(num * f.den, f.num * den).reduce();
}

//boolean operators (in/equality, greater/less than)
bool fraction::operator == (const fraction &f)
{
	fraction x1 = this->getredux();
	fraction x2 = f.getredux();
	return (x1.num == x2.num && x1.den == x2.den);
}

bool fraction::operator != (const fraction &f)
{
	return !(*(this) == f);
}

bool fraction::operator < (const fraction &f)
{
	if(den == f.den)
	{
		return(num < f.num);
	}
	else
	{
		int x1 = num * f.den;
		int x2 = f.num * den;
		return (x1 < x2);
	}
}

bool fraction::operator > (const fraction &f)
{
	if (den == f.den)
	{
		return (num > f.num);
	}
	else
	{
		int x1 = num * f.den;
		int x2 = f.num * den;
		return (x1 > x2);
	}
}

bool fraction::operator >= (const fraction &f)
{
	if(den == f.den)
	{
		return (num >= f.num);
	}
	else
	{
		int x1 = num * f.den;
		int x2 = f.num * den;
		return (x1 >= x2);
	}
}

bool fraction::operator <= (const fraction &f)
{
	if (den == f.den)
	{
		return (num <= f.num);
	}
	else
	{
		int x1 = num * f.den;
		int x2 = f.num * den;
		return (x1 <= x2);
	}
}

//display features
ostream & operator << (ostream &output, const fraction &f)
{
	output << f.num << " / " << f.den;
	return output
}

string fraction::maketext()
{
	ostringstream output;
	output << num << " / " << den;
	return output.str();
}

void fraction::display()
{
	cout << maketext() << endl;
}


//private spots :O

int fraction::getgcd(int n, int d)
{
	if (d > n)
	{
		int temp = n;
		n = d;
		d = temp;
	}

	int x;
	while(d != 0)
	{
		x = n % d;
		n = d;
		d = x;
	}
	return n;
}
