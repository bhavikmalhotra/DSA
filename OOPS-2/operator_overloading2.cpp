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

        Fraction& operator++(){
            numerator = numerator + denominator;
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

int main()){
    Fraction f1(10,2);
    f1.display();
    Fraction f2 = ++f1;
    f2.display();
    Fraction f3 = ++(++f1);
    f3.display();
    f1.display();           //agar upar &fraction operatpor++ use nhi karte toh tph f1 mei 7/1 hi aata kyuki system ek temp coipy ban deta h watch video 7lec 7teh vid for mpore detail.
    //Fraction f2(15,4);
}