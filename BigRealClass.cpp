#include "BigRealClass.h"

istream &operator>>(istream &in, BigReal n)
{
    in >> n.num;
    return in;
}

ostream &operator<<(ostream &out, BigReal n)
{
    out << n.get_Number();
    return out;
}

BigReal::BigReal(double realNumber = 0.0)
{
    num = to_string(realNumber);
}

BigReal::BigReal(string realNumber)
{
    if (isValid(realNumber))
    {
        num = realNumber;
    }
    else
    {
        cout << "number is invalid" << endl;
        exit(-1);
    }
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

bool BigReal::isValid(string num)
{
    if (num[0] == '-')
    {
        sign = 0;
        num = num.substr(1);
    }
    else if (num[0] == '+')
    {
        sign = 1;
        num = num.substr(1);
    }
    else
    {
        sign = 1;
    }
    int count = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '.')
        {
            count += 1;
        }
        if (!isdigit(num[i]) && num[i] != '.' && count >= 1)
            return false;
    }
    return true;
}

void makeEqualAtFront(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    int diff = abs(n - m);

    if (n < m)
    {
        for (int i = 0; i < diff; i++)
        {
            A.insert(A.begin(), 0);
        }
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            B.insert(B.begin(), 0);
        }
    }
}

void makeEqualAtback(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    int diff = abs(n - m);

    if (n < m)
    {
        for (int i = 0; i < diff; i++)
        {
            A.push_back(0);
        }
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            B.push_back(0);
        }
    }
}

BigReal BigReal::operator+(const BigReal &anotherNum)
{
    int i;
    string s1 = num;
    string s2 = anotherNum.num;

    // To store the integer and
    // fractional part of numbers
    vector<int> Ints1, Ints2;
    vector<int> Fracs1, Fracs2;

    // Separating integer and
    // fractional part of s1
    for (i = s1.length() - 1; i > -1; i--)
    {

        // If decimal occurs break
        if (s1[i] == '.')
        {
            break;
        }
        Fracs1.push_back(s1[i] - '0');
    }

    i--;
    for (; i > -1; i--)
    {
        Ints1.push_back(s1[i] - '0');
    }

    // Separating integer and
    // fractional part of s2
    for (i = s2.length() - 1; i > -1; i--)
    {

        // If decimal occurs break
        if (s2[i] == '.')
        {
            break;
        }
        Fracs2.push_back(s2[i] - '0');
    }

    i--;
    for (; i > -1; i--)
    {
        Ints2.push_back(s2[i] - '0');
    }

    // Making number of digits in
    // fractional and Integer
    // part equal
    makeEqualAtFront(Fracs1, Fracs2);
    makeEqualAtback(Ints1, Ints2);

    // Adding fractional parts of
    // s1 and s2
    int n = Fracs1.size();
    int m = Fracs2.size();
    i = 0;
    int carry = 0;

    while (i < n && i < m)
    {

        // Traverse the Fracs1[] and
        // Fracs2[] and add the digit
        // and store the carry
        int sum = Fracs1[i] + Fracs2[i] + carry;

        Fracs1[i] = sum % 10;
        carry = sum / 10;
        i++;
    }

    int N = Ints1.size();
    int M = Ints2.size();
    i = 0;

    // Adding integer part of
    // s1 and s2
    while (i < N && i < M)
    {
        int sum = Ints1[i] + Ints2[i] + carry;
        Ints1[i] = sum % 10;
        carry = sum / 10;
        i++;
    }
    if (carry != 0)
    {
        Ints1.push_back(carry);
    }
    string r;
    for (int i = Ints1.size() - 1; i > -1; i--)
    {
        string c = "";
        c += to_string(Ints1[i]);
        r.push_back(c[0]);
    }
    r.push_back('.');
    for (int i = Fracs1.size() - 1; i > -1; i--)
    {
        string c = "";
        c += to_string(Fracs1[i]);
        r.push_back(c[0]);
    }
    BigReal result(r);
    return result;
}
