#include <iostream>
using namespace std;

//doubkle pointers are pointers which stores address of other pointers
void increment(int **p){
    p = p + 1;              //copy mei changes honge nothing else
}

void increment2(int **p){
    *p = *p + 1;            //chnage rewflect homnhge 
}

void increment3(int **p){
    **p = **p + 1;          //chgnge reflect honerg 
}
int main(){
    int i = 10;
    int *p = &i;
    int **p1 = &p;

    cout<< &p <<endl;
    cout<< p1 <<endl;

    cout<< p <<endl; //address of i
    cout<< *p1 <<endl;//value at p ie. addreess of i
    cout<< &i <<endl;

    cout<< i <<endl;
    cout<< *p <<endl;
    cout<< **p1 <<endl;
}