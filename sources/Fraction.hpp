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

        friend bool checkOverflow(int,int);

        void set_numerator(int);
        void set_denominator(int);
        int getNumerator();
        int getDenominator();

        void reduce();
        friend Fraction convert_float_to_fraction(float );
        friend float convert_fraction_to_float(Fraction);

        Fraction operator+(const Fraction&) const;
        Fraction operator-(const Fraction&) const;
        Fraction operator*(const Fraction&) const;
        Fraction operator/(const Fraction&) const;

        bool operator==(const Fraction& other)const;
        bool operator>(const Fraction& other)const;
        bool operator<(const Fraction& other)const;
        bool operator>=(const Fraction& other)const;
        bool operator<=(const Fraction& other)const;

        friend Fraction operator+(const float& ,const Fraction& other);
        friend Fraction operator-(const float& ,const Fraction& other);
        friend Fraction operator*(const float& ,const Fraction& other);
        friend Fraction operator/(const float& ,const Fraction& other);

        friend bool operator==(const float &,const Fraction& other);
        friend bool operator>( const float &,const Fraction& other);
        friend bool operator<( const float &,const Fraction& other);
        friend bool operator>=(const float &,const Fraction& other);
        friend bool operator<=(const float &,const Fraction& other);

        friend Fraction operator+(const Fraction& other,const float&);
        friend Fraction operator-(const Fraction& other,const float&);
        friend Fraction operator*(const Fraction& other,const float&);
        friend Fraction operator/(const Fraction& other,const float&);

        friend bool operator==(const Fraction& other,const float&);
        friend bool operator>(const Fraction& other, const float& );
        friend bool operator<(const Fraction& other, const float& );
        friend bool operator>=(const Fraction& other,const float& );
        friend bool operator<=(const Fraction& other,const float&);

        Fraction &operator++();
        Fraction &operator--();

        const Fraction operator++(int);
        const Fraction operator--(int);


        friend ostream &operator<< (ostream& , Fraction other);
        friend istream &operator>> (istream& , Fraction &other);

        int GCD(int numerator,int denominator);







    };
}
