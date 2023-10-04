#include "RationalArray.h"

RationalArray::RationalArray(int psize)
{
	size = psize;
	arr = new RationalNumber[psize];
}

RationalArray::RationalArray(const RationalArray& rarray2)
{
	size = rarray2.size;
	arr = new RationalNumber[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rarray2.arr[i];
	}
}

ostream& operator<<(ostream& out, const RationalArray& rarray1)
{
	out << '( ';
	for (int i = 0; i < rarray1.size; i++)
	{
		out << rarray1.arr[i] << ' ';
	}
	out << ')';
	return out;
}

istream& operator>>(istream& in, RationalArray& rarray1)
{
	delete rarray1.arr;
	cout << "Input size: ";
	in >> rarray1.size;
	rarray1.arr = new RationalNumber[rarray1.size];
	cout << "Input " << rarray1.size << "pairs of num/den: ";
	for (int i = 0; i < rarray1.size; ++i)
	{
		in >> rarray1.arr[i];
	}
}

RationalNumber operator*(const RationalArray& rarray1, const RationalArray& rarray2)
{
	RationalNumber result(0, 1);
	for (int i = 0; i < rarray1.size; i++)
	{
		result += rarray1.arr[i] * rarray2.arr[i];
	}
	return result;
}
