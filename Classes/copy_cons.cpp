#include <iostream>
using namespace std;
#include "student.cpp"

int main(){

    student a(20,2001);  //copy assignment operator '='
    student b(10,200);
    student *p = new student;
    a = b;      //copy value of b in object a
    b = *p;
    *p = b;

    student s1(10,1001);
    s1.display();

    student s2(s1); //copy cons
    s2.display();

    student *s3 = new student(s1);
    s3 -> display();

    student *s4 = new student(*s3);
    s4 -> display();  

    delete s3;
    delete s4;
    delete p;  //calls destructor
}