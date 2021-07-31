#include <iostream>
using namespace std;
#include "shallow_deep.cpp"

int main(){
    char name[] ="abcd";
    shallow_deep s1(20,name);   //yaha par hora h deep copy mtlb ek naya name array banega aur waha jake main wala array copy hoga
    s1.display();

    //defalut copy constructor is shallow copy this it will make chnages on th original string too
    name[2]='x';            //yaha par main wale nam emei chane hua h agar shallow copy hota toh change reflect hote 
    s1.name[1] = 'r';
    shallow_deep s2(s1);        //s2 this mei challa gyaa aur s1 gaya s mei see included cpp file
    s2.display();
    s2.name[0] = 'w';       //deep  h toh naya  banega arry copy kakre contents 
    s1.display();           //main wake name mei change hua tha deep copy wale array mei nhi hua toh name[2] par x nhi aaega
    s2.display();
}