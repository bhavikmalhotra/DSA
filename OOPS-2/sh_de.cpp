#include <iostream>
#include <cstring>
using namespace std;
#include "shallow_deep.cpp"

int main(){
    char name[]="abcd";
    shallow_deep s1(20,name);
    s1.display();

    name[3] = 'e';
    shallow_deep s2(24,name);
    s2.display();

    s1.display();

}