#include <ios>
#include <iostream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;

namespace ariel{
/*---------constructors----------*/
    Fraction::Fraction(){

    }


    Fraction::Fraction(int numerator,int denomenator):numerator(numerator),denominator(denomenator){
        if (denominator==0) {
            throw invalid_argument("error!!! : the denominator cant be 0");
        }
        reduce();
    }

  
        
    Fraction::Fraction(float number){
        float a = roundf(number * 1000);        
        float threedigits = a / 1000;        
        
        this->set_numerator( static_cast<int>(threedigits * 1000));
        this->set_denominator(1000);
        this->reduce();
        
    }
/*---------function that convert fraction to float----------*/
    float convert_fraction_to_float(Fraction f){
        float tmp=(float)f.numerator/(float)f.denominator;
        float threedigits = roundf(tmp * 1000);        
        float res=threedigits / 1000;
        return res;
    }

/*---------function that convert  float to fraction----------*/
    Fraction convert_float_to_fraction(float f){
        float a = roundf(f * 1000);        
        float threedigits = a / 1000;        
        Fraction res(1,1);
        res.set_numerator( static_cast<int>(threedigits * 1000));
        res.set_denominator(1000);
        res.reduce();
        return res;
    }


/*---------setters and getters----------*/
    void Fraction::set_numerator(int n){
        this->numerator=n;
    }
    void Fraction::set_denominator(int d){
        this->denominator=d;
    }
    int Fraction::getNumerator(){
        return this->numerator;
    }

    int Fraction::getDenominator(){
        return this->denominator;
    }

/*---------function that simplfy the fraction as possibile----------*/
    void Fraction::reduce(){
        
       
        int gcd=std::__gcd(numerator,denominator);
        numerator/=gcd;
        denominator/=gcd;
        if(this->denominator<0){

            this->denominator*=-1;
            this->numerator*=-1;
        }
    }
/*----------------------------------------operators of fraction with fraction----------------------------------*/
    Fraction Fraction::operator+(const Fraction& other) const{

        if (other.denominator==0) {
            throw runtime_error("denominator cant be 0");
        }

        if ((this->numerator==numeric_limits<int>::max() && this->denominator!=numeric_limits<int>::max())
        ||(other.denominator==numeric_limits<int>::max() && other.denominator !=numeric_limits<int>::max())
        ||(this->numerator<=numeric_limits<int>::min()+100) && (other.numerator<=numeric_limits<int>::min()+100))
        {
            throw std::overflow_error("Error: Overflow during addition.");
        }

       

        int d=this->denominator*other.denominator;
        int n=((d/this->denominator)*this->numerator)+((d/other.denominator)*other.numerator);
        Fraction res(n,d);
        return res;
    }

    Fraction Fraction::operator-(const Fraction& other) const{

        if (other.denominator==0) {
            throw runtime_error("denominator cant be 0");
        }
        
        if ((this->numerator<=numeric_limits<int>::min()+100 && other.numerator<=numeric_limits<int>::min()+100)
        ||(this->numerator>=numeric_limits<int>::max()-100 && other.numerator <=numeric_limits<int>::min()+100))
        {
            throw std::overflow_error("Error: Overflow during addition.");
        }

       
        int d=this->denominator*other.denominator;
        int n=((d/this->denominator)*this->numerator)-((d/other.denominator)*other.numerator);
        Fraction res(n,d);
        return res;
    }

    Fraction Fraction::operator*(const Fraction& other) const{
        

        if (other.denominator==0) {
            throw runtime_error("denominator cant be 0");
        }
        
        if((this->numerator==numeric_limits<int>::max() && this->denominator != numeric_limits<int>::max()) 
        || (this->denominator==numeric_limits<int>::max()&& this->numerator != std::numeric_limits<int>::max()) 
        || (other.numerator == numeric_limits<int>::max()&& other.denominator != std::numeric_limits<int>::max())
        || (other.denominator== std::numeric_limits<int>::max()&& other.denominator != std::numeric_limits<int>::max()))
        {
            throw std::overflow_error("Error: Overflow during addition.");
        }

        

        int n=this->numerator*other.numerator;
        int d=this->denominator*other.denominator;
        Fraction res(n,d);
        return res;
    }

    Fraction Fraction::operator/(const Fraction& other) const{

        if (other.numerator==0 || other.denominator==0) {
            throw runtime_error("denominator cant be 0");
        }
        
        if((this->numerator==numeric_limits<int>::max()&& this->denominator != std::numeric_limits<int>::max()) 
        || (this->denominator ==numeric_limits<int>::max()&& this->numerator < numeric_limits<int>::max()-100) ){
            throw std::overflow_error("Error: Overflow during addition.");
        }

        

        int n=this->numerator*other.denominator;
        int d=this->denominator*other.numerator;
        Fraction res(n,d);
        return res;
    }

    bool Fraction::operator==(const Fraction& other)const{
        float a=convert_fraction_to_float(*this);
        float b=convert_fraction_to_float(other);
        
        if (a==b) {
            return true;
        
        }
        return false;
    }

    bool Fraction::operator>(const Fraction& other)const{
        if (other.denominator==0) {
            throw runtime_error("denominator cant be 0");
        }
        float a=convert_fraction_to_float(*this);
        float b=convert_fraction_to_float(other);

        if (a>b) {
            return true;
        
        }

        // if ((this->numerator*other.denominator)>(this->denominator*other.numerator)) {
        //     return true;
        // }
        return false;

    }

    bool Fraction::operator<(const Fraction& other)const{
        if (other.denominator==0) {
            throw runtime_error("denominator cant be 0");
        }
        float a=convert_fraction_to_float(*this);
        float b=convert_fraction_to_float(other);

        if (a<b) {
            return true;
        
        }

        // if ((this->numerator*other.denominator)<(this->denominator*other.numerator)) {
        //     return true;
        // }
        return false;
    }

    bool Fraction::operator>=(const Fraction& other)const{
        if (other.denominator==0) {
            throw runtime_error("denominator cant be 0");
        }

        if (*this>other || *this==other) {
            return true;
        }
        return false;
    }

    bool Fraction::operator<=(const Fraction& other)const{
        if (other.denominator==0) {
            throw runtime_error("denominator cant be 0");
        }

      if (*this<other || *this==other) {
            return true;
        }
    
        return false;
    }

/*----------------------------------------operators of float with fraction----------------------------------*/
    Fraction operator+(const float &f,const Fraction& other){
       
        Fraction float_to_fraction= convert_float_to_fraction(f);
        Fraction res=float_to_fraction+other;
        return res;
    }
    Fraction operator-(const float& f,const Fraction& other){

        Fraction float_to_fraction= convert_float_to_fraction(f);
        Fraction res=float_to_fraction-other;
        return res;
    }
    Fraction operator*(const float& f,const Fraction& other){
        Fraction float_to_fraction= convert_float_to_fraction(f);
        Fraction res=float_to_fraction*other;
        return res;
    }
    Fraction operator/(const float& f,const Fraction& other){

        if(other.numerator==0 || other.denominator==0){
            throw runtime_error("denominator cant be 0");
        }
        Fraction float_to_fraction= convert_float_to_fraction(f);
        Fraction res=float_to_fraction/other;
        return res;
    }

    bool operator==(const float &f,const Fraction& other){
       float fraction_to_float=convert_fraction_to_float(other);
       if (fraction_to_float==f) {
        return true;
       }
       return false;
    }

    bool operator>(const float &f,const Fraction& other){
        Fraction float_to_fraction=convert_float_to_fraction(f);
        return float_to_fraction>other;
    }

    bool operator<(const float &f,const Fraction& other){
        Fraction float_to_fraction=convert_float_to_fraction(f);
        return float_to_fraction<other;
    }

    bool operator>=(const float &f,const Fraction& other){
        Fraction float_to_fraction=convert_float_to_fraction(f);
        return float_to_fraction>=other;
    }

    bool operator<=(const float &f,const Fraction& other){
        Fraction float_to_fraction=convert_float_to_fraction(f);
        return float_to_fraction<=other;
    }

/*----------------------------------------operators of fraction with float----------------------------------*/
    Fraction operator+(const Fraction& other,const float& f){
      
        Fraction float_to_fraction=convert_float_to_fraction(f);
        Fraction res=float_to_fraction+other;
        return res;
    }
    Fraction operator-(const Fraction& other,const float& f){
       
        Fraction float_to_fraction=convert_float_to_fraction(f);
        Fraction res=other-float_to_fraction;
        return res;
    }
    Fraction operator*(const Fraction& other,const float &f){
       
        Fraction float_to_fraction=convert_float_to_fraction(f);
        Fraction res=float_to_fraction*other;
        return res;
    }
    Fraction operator/(const Fraction& other,const float &f){
       
        if(f==0 || other.denominator==0){
            throw runtime_error("denominator cant be 0");
        }
        Fraction float_to_fraction=convert_float_to_fraction(f);
        Fraction res=other/float_to_fraction;
        return res;
    }

    bool operator==(const Fraction& other,const float& f){
        float fraction_to_float=convert_fraction_to_float(other);
        if (fraction_to_float==f) {
            return true;
        }        
      return false;
    }


    bool operator>(const Fraction& other,const float &f){
        Fraction float_to_fraction=convert_float_to_fraction(f);
        return other>float_to_fraction;
    }
    bool operator<(const Fraction& other,const float &f){
        Fraction float_to_fraction=convert_float_to_fraction(f);
        return other<float_to_fraction;
    }
    bool operator>=(const Fraction& other,const float &f){
        Fraction float_to_fraction(f);
        return other>=float_to_fraction;
    }
    bool operator<=(const Fraction& other,const float &f){
        Fraction float_to_fraction=convert_float_to_fraction(f);
        return other<=float_to_fraction;
    }

    Fraction &Fraction::operator++(){
        this->numerator+=this->denominator;
        return *this;
    }
    Fraction &Fraction::operator--(){
         this->numerator-=this->denominator;
        return *this;
    }


    const Fraction Fraction::operator++(int){
        Fraction res(*this);
        numerator += denominator;
        return res;
    }
    const Fraction Fraction::operator--(int){
        Fraction res(*this);
        numerator -= denominator;
        return res;
    }

    ostream &operator<< (ostream& os, Fraction other){
        os<<other.numerator<<"/"<<other.denominator;
        return os;
    }

    istream &operator>> (istream& is, Fraction &other){
        int numerator, denominator;
        if (is >> numerator >> denominator) {
            if (denominator == 0) {
                throw std::runtime_error("Cannot divide by zero.");
            }
           other = Fraction(numerator, denominator);
        }
        else {
            throw std::runtime_error("Failed to read Fraction from input.");
        }
        return is;
    }
    
}

    // int Fraction::GCD(int n1,int n2){
    //     if(n1<0){
    //         n1=n1*-1;
    //     }
    //      if(n2<0){
    //         n2=n2*-1;
    //     }

    //     int res=1;
    //     if ( n2 > n1) {   
    //         int temp = n2;
    //         n2 = n1;
    //         n1 = temp;
    //     }
    
    //     for (int i = 1; i <=  n2; i++) {
    //         if (n1 % i == 0 && n2 % i ==0) {
    //            res= i;
    //         }
    //     }
    //     return res;
    // }
 
    



