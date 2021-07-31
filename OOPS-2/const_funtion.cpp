#include <iostream>
using namespace std;

class Fraction{
    private:
        int numerator;              //pvt bc we dont want them to get chnaged easily;
        int denominator; 

    public:

        Fraction(){

        }
        Fraction(int numerator,int denominator){
            this -> numerator = numerator;      // this is udes to access the current object
            this -> denominator = denominator;
        }

        int getNumerator() const{
            return numerator;
        }

        int getDenominator() const{
            return denominator;
        }

        void setNumerator(int n){
            numerator = n;
        }

        void setDenominator(int d){
            denominator = d;
        }

        void display() const{
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

        void add_fraction(Fraction const &f2){          
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;

            int sum_numer = x * numerator + (y * f2.numerator);

            numerator = sum_numer;
            denominator = lcm;

            simplify();
        }

        void multiply(Fraction const &f3){
            cout<<f3.numerator<<" "<<f3.denominator<<endl;
            cout<<numerator<<" "<<denominator<<endl;
            numerator = numerator *f3.numerator;
            denominator = denominator * f3.denominator;
            simplify();
        }
};

int main(){
    const Fraction f1;
    f1.display();
}