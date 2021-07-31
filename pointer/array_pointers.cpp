#include <iostream>
using namespace std;

int main(){
    int a[10];
    a[0] = 5;
    a[1] = 10;
    a[2] = 20;

    //array kinda behaves like pointers

    cout<< a <<endl;       // ----->|
    cout<< &a <<endl;      //       | all give same value i.e address of 0th index
    cout<< &(a[0]) <<endl;//        |  
    cout<< &a[0] <<endl;   // ----->|      
    cout<< &a[1] <<endl;
    cout<< &(a[1]) <<endl;
    cout<< *a <<endl;
    cout<< a <<endl;

    //a[i] = *(a+i)

    cout<< *(a+1) <<endl;
    int i = 2;
    cout << *(a+i) <<endl;
    cout<< (a+i) <<endl;


    //differnce between array and pointer
    //are therre breacuse pointer ko alag se memory mei space milti par a ko nhi miotiu usko jo array ke first element ka address hota h wahi milta h bas tavbhi diff hote h array aur pomnter mei.
    //1) differne tvalue of sizeof()
    //       array is not given any specific memory location rather than the array itself so if we write a it prints the address of 1st element
    //       whereas pointer is given a apcefic address in the memory therefore the have differnt value of sizeof()
    //2)& operator same reason asd above
    //a symbol tree mei enter hota h usse chage nhyi kar sakte pointer ko kar sakte h eg; a!= p but we can do p=a
    int j = 2;
    int *p = &i;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(p)<<endl;

    int *q = &a[0];

    cout<< q <<endl;
    cout<< a <<endl;

    cout<< &q <<endl;//address where the pointer is stored
    cout<< &a <<endl;

    cout<<sizeof(a)<<endl;//sizer of full array
    cout<<sizeof(q)<<endl;//size of pointer 

    q = q+1 ; // we can do this pointer next par point karega kyuki memmory assign ho rakhi h isilite we ca change
    // we canno5t do a=a+1 or a++ kyuki a ko aur koi memory assign hi mhi hui h WE CANNOT REASSIGN MEMORY

    int arr[] = {1,2,3};
    int *t = arr;
    cout<< t[1]<<endl;
}
