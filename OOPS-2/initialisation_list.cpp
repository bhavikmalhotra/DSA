#include <iostream>
using namespace std;

//if we want ki humara rollno const. rahe aur baar baar change na hoye we can use const 
class student{
    public:
        int age;
        const int rollno;
        int &x;         //we also need to initialise refernce variables at time of creation(thisnis a refernce variable to age)

    student(int r,int a): rollno(r), age(a), x(this->age){         //we need touse this in x to specify what age we are talking about
            //agar const mei hum rollno assign kar dete toh vo roll no hatr objmei use hota isi;liye we use inititailisation list.
    }
};

int main(){
    student s1(101,20);

}