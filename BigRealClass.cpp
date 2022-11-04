#include "BigRealClass.h"


BigReal::BigReal(double realNumber = 0.0)
{
    num = to_string(realNumber);
}

BigReal::BigReal(string realNumber)
{
    num = realNumber;
}

BigReal::BigReal(int realNumber)
{
    BigDecimalInt n(realNumber);
    num = n.getNumber();
}

BigReal::BigReal(BigDecimalInt realNumber)
{
    num = realNumber.getNumber();
}

string BigReal::get_Number()
{
    return num;
}

// function for + operator
void makeEqualAtFront(vector<int>& A,
                      vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    int diff = abs(n - m);
   
    if (n < m) {
        for (int i = 0; i < diff; i++) {
            A.insert(A.begin(), 0);
        }
    }
    else {
        for (int i = 0; i < diff; i++) {
            B.insert(B.begin(), 0);
        }
    }
}

// function for + operator
void makeEqualAtback(vector<int>& A,
                     vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    int diff = abs(n - m);
   
    if (n < m) {
        for (int i = 0; i < diff; i++) {
            A.push_back(0);
        }
    }
    else {
        for (int i = 0; i < diff; i++) {
            B.push_back(0);
        }
    }
}

BigReal BigReal::operator+ (BigReal anotherNum)
{
    int i;
    string s2 = anotherNum.num;

    vector<int> Intnum, Ints2;
    vector<int> Fracnum, Fracs2;
   
    for (i = num.length() - 1; i > -1; i--) {
   
        if (num[i] == '.') {
            break;
        }
        Fracnum.push_back(num[i] - '0');
    }
   
    i--;
    for (; i > -1; i--) {
        Intnum.push_back(num[i] - '0');
    }
   
    for (i = s2.length() - 1; i > -1; i--) {
   
        if (s2[i] == '.') {
            break;
        }
        Fracs2.push_back(s2[i] - '0');
    }
   
    i--;
    for (; i > -1; i--) {
        Ints2.push_back(s2[i] - '0');
    }
   
    makeEqualAtFront(Fracnum, Fracs2);
    makeEqualAtback(Intnum, Ints2);

    int n = Fracnum.size();
    int m = Fracs2.size();
    i = 0;
    int carry = 0;
   
    while (i < n && i < m) {
        int sum = Fracnum[i]
                  + Fracs2[i]
                  + carry;
   
        Fracnum[i] = sum % 10;
        carry = sum / 10;
        i++;
    }
   
    int N = Intnum.size();
    int M = Ints2.size();
    i = 0;
   
    while (i < N && i < M) {
        int sum = Intnum[i]
                  + Ints2[i]
                  + carry;
        Intnum[i] = sum % 10;
        carry = sum / 10;
        i++;
    }

    if (carry != 0)
        Intnum.push_back(carry);
  
    string result = "";

    for (int i = Intnum.size() - 1; i > -1; i--) {
        result.push_back(Intnum[i]);
    }

    result.push_back('.');

    for (int i = Fracnum.size() - 1; i > -1; i--) {
        result.push_back(Fracnum[i]);
    }

    return result;
}