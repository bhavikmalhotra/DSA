#include <iostream>
using namespace std;

class student{
    //class by defalut private hoti h mtlb class ke bahar not accessible
    int pvt;
    public:
        int rollNo;
        int age;

        student(){
            cout<<"Default Constructort called"<<endl;
        }

        student(int n){
            cout<<"Parameterised construator called"<<endl;
            rollNo = n;
        }
        
        void display(){
            cout<<rollNo<<" "<<age<<endl;
        }

        int private_display(){
            return pvt;  //ye retunr karegi garbage value kyuki pvt ko main mei hum access nhi kar sakte kyuki vo pvt hai toh jab hum pvt_display call karenge toh garbage
        }                //vakue print hogi

        void setter(int a){
            pvt = a;
        }

        void getter(){
            cout<< pvt <<endl;
        }

    
};

int main(){
    //static allocation
    student s1(444);
    s1.rollNo = 101906221;
    s1.age = 5;
    s1.setter(10101);
    s1.getter();
    cout<< s1.rollNo <<endl;
    cout<< s1.age <<endl;

    //dynamic allocation
    student *a = new student(4);//paarmetrised cons call hoga
    a->age = 10;
    a->rollNo = 401906012;
    cout<< a->age <<endl;
    cout<< a->rollNo <<endl;

    //function
    cout<<"--funtion--"<<endl;
    s1.display();
    a->display();
    a->setter(5);
    a->getter();
    
}