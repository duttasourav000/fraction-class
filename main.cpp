#include "include/Fraction.h"

using namespace std;

void checkDenominatorZero()
{
    try
    {
        Fraction f(10, 0);
    }
    catch(const char* e)
    {
        cout << e << endl;
    }
}

void checkFractionWithZeros()
{
    Fraction a(0, 10), b(80, 7);
    
    Fraction c = a * b;
    c.display();
    cout << endl;
}

void checkFractionsWithIntegers()
{
    Fraction a(0, 10), b(80, 7);

    Fraction d = a * 5;
    d.display();
    cout << endl;

    Fraction e = 6 * b;
    e.display();
    cout << endl;
}

void checkFractions()
{
    Fraction a(10, 11), b(9, 8);

    Fraction c = a * b;
    c.display();
    cout << endl;

    Fraction d(4, 1);
    c = c * d;
    c.display();
    cout << endl;

    c = a * 11 * b * c * 7;
    c.display();
    cout << endl;
}

int main(void)
{

    checkDenominatorZero();
    checkFractions();
    checkFractionWithZeros();
    checkFractionsWithIntegers();

    return 0;
}