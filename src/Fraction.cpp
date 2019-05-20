#include "../include/Fraction.h"

// Calculates greates common divisor of the two numbers
int getGCD(int a, int b)
{
    if (b == 0)
        return a;

    return getGCD(b, a % b);
}

// Constructor of the Fraction class
Fraction::Fraction(int numeratorInput, int denominatorInput)
{
    // denominator cannot be 0
    if (denominatorInput == 0)
    {
        throw "Division by zero condition!";
    }

    // get the reduced fraction
    int gcd = getGCD(numeratorInput, denominatorInput);
    numerator = numeratorInput / gcd;
    denominator = denominatorInput / gcd;
}

// Overload the * operation to support operations of the form F1 * F2
Fraction Fraction::operator*(Fraction otherFraction)
{
    int gcd1 = getGCD(numerator, otherFraction.denominator);
    int gcd2 = getGCD(denominator, otherFraction.numerator);

    int resultNumerator = (numerator / gcd1) * (otherFraction.numerator / gcd2);
    int resultDenominator = (denominator / gcd2) * (otherFraction.denominator / gcd1);

    Fraction result(resultNumerator, resultDenominator);
    return result;
}

// Overload the * operation to support operations of the form F1 * 3
Fraction Fraction::operator*(int otherFraction)
{
    int gcd = getGCD(otherFraction, denominator);
    int resultNumerator = numerator * (otherFraction / gcd);

    Fraction result(resultNumerator, denominator / gcd);
    return result;
}

// function to display the fraction
void Fraction::display()
{
    if (numerator == 0)
        std::cout << numerator;
    else
        std::cout << numerator << "/" << denominator;
}

// Overload the * operation to support operations of the form 3 * F1
Fraction operator*(int otherFraction, Fraction thisFraction)
{
    int gcd = getGCD(otherFraction, thisFraction.denominator);
    int resultNumerator = thisFraction.numerator * (otherFraction / gcd);

    Fraction result(resultNumerator, thisFraction.denominator / gcd);
    return result;
}