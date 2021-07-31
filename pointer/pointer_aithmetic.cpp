#include <iostream>
using namespace std;

int main(){
    int i=10;
    int *p = &i;

    cout<< p <<endl; // see intro if doubt 
    cout<< *p <<endl;
    p = p+1;
    cout<< sizeof(i) <<endl;//size for int is 4
    cout<< p <<endl;//adds 4 bytes because size of p is 4 and we do +1 therfore it means add 1 p i.e 4 bytes 

    //this functionality is useful in array to point to the the next position in the array not in any any other cae this funbcyiomnality is usefull
    p = p + 1;
    cout<< p <<endl;// adds 4 more

    double j = 10.22;
    double *q = &j;

    cout<< q <<endl;
    cout<< sizeof(j) <<endl;//size fro double is 8 therefore 8 bytes is increased in the address i the next line
    q = q+1;
    cout<< q <<endl;

}