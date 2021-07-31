#include <iostream>
using namespace std;

//this keyword holds address of current object
//this is pointer variable and a special keyword


class student{
    int pvt;
    public:
        int rollNo;
        int age;

        student(int rollNo){        //this is used rto refer to the current obj 

            this -> rollNo = rollNo;        //agar yaha thus nhi alagte toh rolno=rolno ho jata parameter wala parmeter mei hi store ho jata isiliye 
            cout<< this -> rollNo <<endl;   //==(*this).rollno = rollno; this behave like pointer
        }

        student(int a ,int r){
            cout<<"Parameterized Constructort called"<<endl;
            cout<<"this : "<< this <<endl;                      //ponter h toh adfdress of cyurrent obg
            age = a;
            rollNo = r;
        }

        void display(){
            cout<<rollNo<<" "<<age<<endl;
        }


};

int main(){
    student s1(10,101);
    cout<<"Address of s1: "<<&s1<<endl;

    student s2(7);
    s2.display();
}