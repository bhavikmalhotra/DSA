#include <iostream>
using namespace std;

int main(){

    int arr[5]={4,13,54,12,0};
    int *p = &arr[0] , *q = p+3;
    cout<<p<<endl;
    cout<<arr<<endl;
    cout<<*p<<endl;
    cout<<q<<endl;
    cout<<*q<<endl;
    cout<<*q-*p;
    cout<<q-p;
    return 0;

}