
#include<iostream>
using namespace std;


//ALGO  fib(n) = fib(n-1) + fib(n-2);
//base case banao ie 0 aur 1 ke liye
//hypostheseis assume karklo true hai



int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    int smallOutput1 = fibonacci(n-1);  //induction hypo assume
    int smallOutput2 = fibonacci(n-2);  //induction hypo assume
    return smallOutput1+smallOutput2;

}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n);

}
