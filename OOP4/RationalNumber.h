#pragma once

using namespace std;

class RationalNumber
{
private:
	int num, den;

	int const NOD();
	void reduce();


public:
	RationalNumber();
	RationalNumber(int a, int b);
	RationalNumber(const RationalNumber& x);

	void set(int a = 0, int b = 0)
	{
		num = a;
		den = b;
	}
	int get_num() const
	{
		return num;
	}
	int get_den() const
	{
		return den;
	}

	void operator+=(const RationalNumber& y);
	RationalNumber operator+(const RationalNumber& y);
	RationalNumber& operator++();
	RationalNumber& operator++(int);
	RationalNumber& operator=(const RationalNumber& y);
	void print();

	RationalNumber operator*(const RationalNumber& y) const;

	friend RationalNumber operator-(const RationalNumber& x, const RationalNumber& y);

	~RationalNumber();
};
RationalNumber operator/(const RationalNumber& x, const RationalNumber& y);
ostream& operator<<(ostream& out, const RationalNumber& x);
istream& operator>>(istream& in, RationalNumber& x);