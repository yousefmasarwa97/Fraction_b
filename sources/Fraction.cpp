#include<iostream>
#include "Fraction.hpp"
#include <fstream>
#include <sstream>
#include <cmath>


namespace ariel{

    Fraction::Fraction(){}


    Fraction::Fraction(int numerator,int denomenator):numerator(numerator),denominator(denomenator){

    }

  
        
    Fraction::Fraction(float number){
        float a = roundf(number * 1000);        
        float threedigits = a / 1000;        
        
        this->set_numerator( static_cast<int>(threedigits * 1000));
        this->set_denominator(1000);
    }

    void Fraction::set_numerator(int n){
        this->numerator=n;
    }
    void Fraction::set_denominator(int d){
        this->denominator=d;
    }
    int Fraction::get_numerator(){
        return this->numerator;
    }

    int Fraction::get_denominator(){
        return this->denominator;
    }

    Fraction Fraction::reduce(){
        int a=this->get_numerator();
        int b=this->get_denominator();
        int gcd;
        gcd=GCD(a,b);
        Fraction res(a/gcd,b/gcd);
        return res;
    }

    Fraction Fraction::operator+(const Fraction& other) const{
        return other;
    }

    Fraction Fraction::operator-(const Fraction& other) const{
        return other;
    }

    Fraction Fraction::operator*(const Fraction& other) const{
        return other;
    }

    Fraction Fraction::operator/(const Fraction& other) const{
        return other;
    }

    bool Fraction::operator==(const Fraction& other)const{
        return true;
    }
    bool Fraction::operator>(const Fraction& other)const{
        return true;
    }
    bool Fraction::operator<(const Fraction& other)const{
        return true;
    }
    bool Fraction::operator>=(const Fraction& other)const{
        return true;
    }
    bool Fraction::operator<=(const Fraction& other)const{
        return true;
    }


    Fraction operator+(float a,const Fraction& other){
        return other;
    }
    Fraction operator-(float a,const Fraction& other){
        return other;
    }
    Fraction operator*(float a,const Fraction& other){
        return other;
    }
    Fraction operator/(float a,const Fraction& other){
        return other;
    }

    bool operator==(float f,const Fraction& other){
        return true;
    }
    bool operator>(float f,const Fraction& other){
        return true;
    }
    bool operator<(float f,const Fraction& other){
        return true;
    }
    bool operator>=(float f,const Fraction& other){
        return true;
    }
    bool operator<=(float f,const Fraction& other){
        return true;
    }

    Fraction &Fraction::operator++(){
        return *this;
    }
    Fraction &Fraction::operator--(){
        return *this;
    }


    const Fraction Fraction::operator++(int){
        return *this;
    }
    const Fraction Fraction::operator--(int){
        return *this;
    }

    ostream &operator<< (ostream& os,const Fraction other){
        return os;
    }
    istream &operator>> (istream& is,const Fraction other){
        return is;
    }

    int Fraction::GCD(int n1,int n2){
        int res=1;
        if ( n2 > n1) {   
            int temp = n2;
            n2 = n1;
            n1 = temp;
        }
    
        for (int i = 1; i <=  n2; ++i) {
            if (n1 % i == 0 && n2 % i ==0) {
               res= i;
            }
        }
        return res;
    }
 
    


}
