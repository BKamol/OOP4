#pragma once
#include "RationalNumber.h"
#include <iostream>

using namespace std;

class RationalArray
{
private:
	int size;
	RationalNumber* arr;

public:
	RationalArray(int psize = 0);
	RationalArray(const RationalArray& rarray2);

	int get_size() const { return size; };
	RationalNumber* get_values() const { return arr; };

	RationalNumber operator[](int index) { return arr[index]; };
	friend ostream& operator<<(ostream& out, const RationalArray& rarray1);
	friend istream& operator>>(istream& in, RationalArray& rarray1);
	friend RationalNumber operator*(const RationalArray& rarray1, const RationalArray& rarray2);
	

	~RationalArray() { delete arr; }

};