#include "RationalNumber.h"
#include <iostream>

using namespace std;

int const RationalNumber::NOD()
{
    int A = num;
    int B = den;
    while (A != 0 && B != 0)
        if (A > B) A = A % B;
        else B = B % A;
    return A + B;
}

void RationalNumber::reduce()
{
    int nod = NOD();
    this->den = this->den / nod;
    this->num = this->num / nod;

}

RationalNumber::RationalNumber()
{
    this->num = 1;
    this->den = 1;
}

RationalNumber::RationalNumber(int a, int b)
{
    this->num = a;
    this->den = b;
}

RationalNumber::RationalNumber(const RationalNumber& x)
{
    this->num = x.num;
    this->den = x.den;
}

void RationalNumber::operator+=(const RationalNumber& y)
{
    this->num = this->num * y.den + this->den * y.num;
    this->den = this->den * y.den;
}

RationalNumber RationalNumber::operator+(const RationalNumber& y)
{
    RationalNumber z(0, 1);
    z.num = this->num * y.den + this->den * y.num;
    z.den = this->den * y.den;
    return z;
}

RationalNumber& RationalNumber::operator++()
{
    this->num += this->den;
    return *this;
}

RationalNumber& RationalNumber::operator++(int)
{
    RationalNumber c(*this);
    this->num += this->den;
    return c;
}

RationalNumber& RationalNumber::operator=(const RationalNumber& y)
{
    this->num = y.num;
    this->den = y.den;
    return *this;
}

void RationalNumber::print()
{
    this->reduce();
    cout << this->num << '/' << this->den << ' ';
}

RationalNumber RationalNumber::operator*(const RationalNumber& y) const
{
    RationalNumber product(1, 1);
    product.num = this->num * y.num;
    product.den = this->den * y.den;
    return product;
}


RationalNumber::~RationalNumber()
{
    //cout << "Delete RationalNumber Object" << endl;
}

RationalNumber operator-(const RationalNumber& x, const RationalNumber& y)
{
    RationalNumber z(0, 1);
    z.num = x.num * y.den - x.den * y.num;
    z.den = x.den * y.den;
    return z;
}

RationalNumber operator/(const RationalNumber& x, const RationalNumber& y)
{
    RationalNumber z(0, 1);
    int num = x.get_num() * y.get_den();
    int den = x.get_den() * y.get_num();
    z.set(num, den);
    return z;
}

ostream& operator<<(ostream& out, const RationalNumber& x)
{
    out << x.get_num() << '/' << x.get_den() << ' ';
    return out;
}

istream& operator>>(istream& in, RationalNumber& x)
{
    int num = 0;
    int den = 1;
    in >> num >> den;
    x.set(num, den);
}
