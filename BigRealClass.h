#ifndef BIGREALCLASS_H
#define BIGREALCLASS_H

#include <iostream>
#include <string>
#include "BigDecimalIntClass.h"

using namespace std;

class BigReal
{
    private:
        string num;
    public:
        BigReal(double realNumber);
        BigReal(string realNumber);
        BigReal(int realNumber);
        BigReal(BigDecimalInt realNumber);
        string get_Number();
        BigReal operator+ (BigReal anothernum);
};


#endif