#include <iostream>
using namespace std;

//char behave differntly beacause of the way cout is implemanted ; char prints till it finds the null char;

int main(){
    int a[] = {1,2,3};
    char b[] = "abc";

    cout<< a <<endl;//prints address of a
    cout<< *a <<endl;
    cout<< b <<endl;//thisd prints thew entire strings at that array till it encounters the null character this is because of the way cout is implemented.

    char *c = &b[0];
    cout<< c <<endl;//expected to print address like the other pointers but behave diffrebtly because the way cout is implemented

    char d = 'g';
    char *d1 = &d;

    cout<< d <<endl;
    cout<< d1 <<endl;//expected to print the address but we know char prints the value at the memory but the interesting thing that happend here is that
                     //it printed the value but it did not stop after it it printed till it found the null character in the memory;
}