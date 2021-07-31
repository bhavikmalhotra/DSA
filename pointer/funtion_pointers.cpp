#include <iostream>
using namespace std;

void print(int *p){
    cout<< *p <<endl;
}

void IncrementPointer(int *p){
    p = p + 1;
}

void Increment(int *p){
    (*p)++;
}

int main(){
    int i = 10;
    int *q = &i;
    print(q);

    //call by value example
    cout<< q <<endl;//remains the same bec we call by value a copy is sent thus remains the same even after calling incrementpointer function
    IncrementPointer(q);
    cout<< q <<endl;//call by value stays the same a copy is sent not the orignal;

    cout<< *q <<endl;//isme change isiliye hota h kyuki cop[y toh ban jati h par inrement jab karte vo toh uss address pe jake ++ kar deti h p ko aur vo toh reflect hota hi h 
    Increment(q);
    cout<< *q <<endl;//address is getting passed by value not the actual value thus chnage is reflected 
}
