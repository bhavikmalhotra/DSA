#include <iostream>
using namespace std;

//stactic class ka hota h object ka nhi 
//static siraf static ko hi access akrega

class student{
    static int totalstudent;
    public:
        int age;
        int rollno;

    student(){
        totalstudent++;
    }
    
  
    static int getTotalstudent(){       //static funtion statyic variavlre ko hi access kar paega
        return totalstudent;
    }

};

int student :: totalstudent = 0;

int main(){
    student s1,S2,S3;
    cout<<s1.age<<endl;
    cout<<s1.rollno<<endl;
    //cout<<student :: totalstudent<<endl;
    cout<<student :: getTotalstudent();

}