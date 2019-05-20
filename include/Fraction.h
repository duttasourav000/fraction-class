#include <iostream>

// Fraction class to support fractions of type 5/8
// stores the numerator and denominator as integers
class Fraction
{
    int numerator;
    int denominator;

    public:

    // Constructor of the Fraction class
    Fraction(int numeratorInput, int denominatorInput);
    
    // Overload the * operation to support operations of the form F1 * F2
    Fraction operator*(Fraction otherFraction);

    // Overload the * operation to support operations of the form F1 * 3
    Fraction operator*(int otherFraction);

    // function to display the fraction
    void display();

    // Overload the * operation to support operations of the form 3 * F1
    friend Fraction operator*(int otherFraction, Fraction thisFraction);
};