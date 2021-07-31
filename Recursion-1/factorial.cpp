#include <iostream>
using namespace std;

//recursion is calling the fucntion again and again but with a smaller value than before.

//imagine this factorial as a glass of sabse pehle main mei factorial(5) pass hota h vo wait karta h ans ki main sabse neeche h glass mei
//factorial(5) factorial(4) ko call karta h line 10 par ans ki wait karra h factorial(4) on line 10
//sabse neeche main wait karra h uske upar factorial(5) uske upar factorial(4) and so on
//phir n=1 hua ek time par ab vo factorial(0) ko call karega n=0 toh ab else if state par jaega aur 1 return karega funtion factorial(0) factorial(1) ko
//glass mei sabse upar factorial(0) hai iusse 1 return hua factorial(1) ab factorial(1) return karega n*smalloutput i.e. 1*1=1 so 1 return hoga factorial(2) ko
//factorial(2) return karega n*small output i.e 2*1=2 2 return hoga factorial(3) ko
//factorial(3) return karega n*smalloutput ie 3*2= 6 return hoga factorial(4)
//and so on 

//so ek glass mei sabse neeche main wait karta h retunr value uske upoar fuction wait karte h sabse upar se phir value return hona start hgoti h aur end mei main par value return hoti h


//base case sahi se karlo
//assume karlena choti prob ke liye chal jaega
//badi problem  ke liye sahi se code karo
int factorial(int n){
    if (n == 0){            //base case
        return 1;
    }
    
    int smallOutput = factorial(n-1);   //assume choti prob ke liye chal jaega
    int out = n*smallOutput;               //badi prob ka code
    return out;
        
}

//mera method
int fact(int n){
    int ans = 1 ;
    if(n>1){
        ans *= n*fact(n-1);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int output = factorial(n);
    cout<< output <<endl;

}