#ifndef BIGREALCLASS_H
#define BIGREALCLASS_H

#include <iostream>
#include <string>
#include <cstring>
#include "BigDecimalIntClass.h"

using namespace std;

class BigReal
{
private:
    string num;
    int sign;
    int size;
    bool isValid(string num);

public:
    BigReal(double realNumber);
    BigReal(string realNumber);
    BigReal(int realNumber);
    BigReal(BigDecimalInt realNumber);
    string get_Number();
    BigReal operator+(const BigReal &anothernum);
    BigReal operator-(const BigReal &anothernum);
    friend ostream &operator<<(ostream &out, BigReal n);
    friend istream &operator>>(istream &in, BigReal n);
};

#endif