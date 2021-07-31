#include <iostream>
using namespace std;

int main(){
    int i;
    i = 10;

    int *p = &i;

    //*p is used to point to the value stored in address p points to.
    cout<< *p <<endl; 
    //p stores the address of the variable it is pointed to.
    cout<< p <<endl;
    cout<< &i <<endl;
    cout<< &p <<endl;

    cout<<sizeof(i)<<endl;

    i++;

    //i increases
    cout<< i <<endl;
    //address remains the same therfore no chnage in p
    cout<< p <<endl;
    //i is incremented therefore p is also incremented
    cout<< *p <<endl;

    *p = 12;

    //i alos chnages values as we chnage value of * p as both i=x and *p=x are the same operation.
    cout<< i <<endl;
    cout<< *p <<endl;

    i = 13;
    cout<< p <<endl;
    cout<< *p <<endl;
    cout<< i <<endl;

    //v. imp
    //p points to address of i thus p will give address of i and *p will give value at that address that ios va;ue of i and
    // &p will give address of the place where the pointer p is stored
    int *q = p;
    //if we pointe the previous p to another pointer we see the following results
    cout<< &p <<endl;//gives address of the place where pointer p is saved in the memory
    cout<< p <<endl;//gives address of i
    cout<< q <<endl;//gives address of i
    cout<< *q <<endl;//value of i 

    //int *s never intiialise pointers like this if we have no value to initialiize we can do
    int *s = 0;
    

}