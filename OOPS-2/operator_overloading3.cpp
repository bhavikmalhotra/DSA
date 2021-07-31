#include <iostream>
using namespace std;

//we use & when we dont want ot make a copy we just want to use a refgernece and we use const so that we cannot chnage value using that &(refence made)
//cthe func that do not chnage value of obj variables are capable of becoming cvonst func.

class Fraction{
    private:
        int numerator;              //pvt bc we dont want them to get ch naged easily;
        int denominator; 

    public:
        Fraction(int numerator,int denominator){
            this -> numerator = numerator;      // this is udes to access the current object
            this -> denominator = denominator;
        }

        void display(){
            cout << this -> numerator <<"/"<< denominator<<endl;  //this use karna is not zaroori idhar kyuki yaha scoper ki koi dikkat nhi h
        }
        
        void simplify(){
            int gcd = 1;
            int j = min(numerator,denominator);
            for(int i = 1 ; i <= j; i++){
                if(numerator%i == 0 && denominator%i == 0){
                    gcd = i;
                }
            }
            numerator = numerator/gcd;
            denominator = denominator/gcd;
        }

        //pre incremnt
        Fraction& operator++(){
            numerator = numerator + denominator;
            simplify();
            return *this;
        }

        //post ncrement
        Fraction operator++(int){
            Fraction fNew(numerator,denominator);
            numerator = numerator + denominator;
            simplify();
            fNew.simplify();
            return fNew;
        }

        Fraction& operator+=(Fraction const &f2){
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;
            int sum_numer = x * numerator + (y * f2.numerator);
            numerator = sum_numer;
            denominator = lcm;
            simplify();
            return *this;
        }

        Fraction add(Fraction const &f2) const{          
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;
            int sum_numer = x * numerator + (y * f2.numerator);
            int num = sum_numer;
            int den = lcm;
            Fraction fNew(num,den);
            fNew.simplify();
            return fNew;
        }

        Fraction operator+(Fraction const &f2) const{          
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;
            int sum_numer = x * numerator + (y * f2.numerator);
            int num = sum_numer;
            int den = lcm;
            Fraction fNew(num,den);
            fNew.simplify();
            return fNew;
        
        }


        Fraction multiply(Fraction const &f3) const{
            int num = numerator *f3.numerator;
            int den = denominator * f3.denominator;
            Fraction f(num,den);
            f.simplify();
            return f;
        }

        Fraction operator*(Fraction const &f3) const{
            int num = numerator *f3.numerator;
            int den = denominator * f3.denominator;
            Fraction f(num,den);
            f.simplify();
            return f;
        }
};
int main(){
    Fraction f1(2,5);
    Fraction f2 (4,5);
    (f1 += f2) += f2;
    f2.display();
    f1.display();
}