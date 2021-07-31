#include <iostream>
#include "Fraction.cpp"
using namespace std;

class Fraction{
    private:
        int numerator;              //pvt bc we dont want them to get chnaged easily;
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

        //neeche humen &f2 isiliye liya kyuki f2 ke bas variable abs read karne h humme toh faltiu mei copy construator kyu call karna h aur new mem use karni h
        //usse acha hum pass by refernce kar dete h copy chale jaegi yaha class mei f2 ki au hum change wagera read kar paenge
        //dikkat yaha ye aayi ki agar hum yaha f2 ko change kar diayt toh neeche main mei bhi chnage ho jaega kyuki &f2 is just a reference i.e same hi cheez hai
        //agar yaha f2 mei change kiya toh vo neeche main mei bhi reflect hhoga
        //so yaha siraf read access dene ke liye we use const const use karke hum bas read kar paenge usse chnage nhi
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
    Fraction f1(10,2);
    f1.display();
    Fraction f2(15,4);
    f2.display();
    f1.add_fraction(f2);
    f1.display();

    Fraction m1(10,3);
    f1.multiply(m1);
    f1.display();
}