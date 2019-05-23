#include <climits>
#include "include/Fraction.h"

using namespace std;

void testDenominatorZero()
{
    cout << "testDenominatorZero" << endl;
    try
    {
        Fraction f(10, 0);
    }
    catch(const char* e)
    {
        cout << e << endl;
    }
}

void testFractionWithZeros()
{
    cout << "testFractionWithZeros" << endl;
    Fraction a(0, 10), b(80, 7);
    
    Fraction c = a * b;
    c.display();
    cout << endl;
}

void testFractionsWithIntegers()
{
    cout << "testFractionWithZeros" << endl;
    Fraction a(0, 10), b(80, 7);

    Fraction d = a * 5;
    d.display();
    cout << endl;

    Fraction e = 6 * b;
    e.display();
    cout << endl;
}

void testFractions()
{
    cout << "testFractions" << endl;
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

void testExtremeBounds()
{
    cout << "testExtremeBounds" << endl;
    Fraction a(INT_MAX, 1), b(1, INT_MAX);
    (a * b).display();
    cout << endl;

    Fraction c(INT_MAX, INT_MAX - 1);
    ((INT_MAX - 1) * c).display();
    cout << endl;

    Fraction d(1, INT_MIN);
    d.display();
    cout << endl;

    Fraction e(INT_MIN, 1);
    e.display();
    cout << endl;

    // this is wrong due to integer overflow
    ((INT_MAX) * e).display();
    cout << endl;
}

void testNegativeFractions()
{
    cout << "testNegativeFractions" << endl;
    {
        Fraction a(-10, 2), b(3, -5);
        (a * b).display();
        cout << endl;

        Fraction c(-10, 2), d(-3, 5);
        (c * d).display();
        cout << endl;

        Fraction e(-10, -2), f(-3, -5);
        (e * f).display();
        cout << endl;

        Fraction g(10, -2), h(3, -5);
        (g * h).display();
        cout << endl;

        (a * b * c * d * e * f * g).display();
        cout << endl;
        
        (a * b * c * d * e * f * g * h).display();
        cout << endl;
        
        ((a * b) * c * (((d * e) * f) * g) * h).display();
        cout << endl;
        
        (a * (b * c) * (d * e * f) * (g * h)).display();
        cout << endl;
    }
    {
        Fraction a(-10, 2), b(3, 5);
        (a * b).display();
        cout << endl;

        Fraction c(10, -2), d(3, 5);
        (c * d).display();
        cout << endl;

        Fraction e(10, 2), f(-3, 5);
        (e * f).display();
        cout << endl;

        Fraction g(10, 2), h(3, -5);
        (g * h).display();
        cout << endl;

        (b * c * d * e * f * g * h).display();
        cout << endl;

        (a * b * c * d * e * f * g * h).display();
        cout << endl;
        
        ((a * b) * c * (((d * e) * f) * g) * h).display();
        cout << endl;
        
        (a * (b * c) * (d * e * f) * (g * h)).display();
        cout << endl;
    }

    Fraction a(-11, 2);
    a.display();
}

int main(void)
{
    testDenominatorZero();
    testFractions();
    testFractionWithZeros();
    testFractionsWithIntegers();
    testExtremeBounds();
    testNegativeFractions();

    return 0;
}