#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>

using namespace std;

namespace ariel{
    class Fraction{
        private:
        int numerator;
        int denominator;

        public:
        Fraction();
        Fraction(int numerator,int denominator);
        Fraction(float fraction);

        void set_numerator(int);
        void set_denominator(int);
        int get_numerator();
        int get_denominator();

        Fraction reduce();

        Fraction operator+(const Fraction&) const;
        Fraction operator-(const Fraction&) const;
        Fraction operator*(const Fraction&) const;
        Fraction operator/(const Fraction&) const;

        bool operator==(const Fraction& other)const;
        bool operator>(const Fraction& other)const;
        bool operator<(const Fraction& other)const;
        bool operator>=(const Fraction& other)const;
        bool operator<=(const Fraction& other)const;

        friend Fraction operator+(float ,const Fraction& other);
        friend Fraction operator-(float ,const Fraction& other);
        friend Fraction operator*(float ,const Fraction& other);
        friend Fraction operator/(float ,const Fraction& other);

        friend bool operator==(float ,const Fraction& other);
        friend bool operator>(float ,const Fraction& other);
        friend bool operator<(float ,const Fraction& other);
        friend bool operator>=(float ,const Fraction& other);
        friend bool operator<=(float ,const Fraction& other);

        Fraction &operator++();
        Fraction &operator--();

        const Fraction operator++(int);
        const Fraction operator--(int);


        friend ostream &operator<< (ostream& , Fraction other);
        friend istream &operator>> (istream& , Fraction other);

        int GCD(int numerator,int denominator);







    };
}
