#include <iostream>
using namespace std;

//RECURSION
//1>> BASE 
//2>> RECURSIVE CALL
//3>> SMALL CALCULATION

int last_index(int a[],int size, int x){
    if(size == 0){
        return -1;
    }

    int last = last_index(a+1,size-1,x);        //according to pmi just assume humme last index mil jaega correct
    if(last == -1){
        if(a[0] == x){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        return last+1;
    }

    if(a[size-1] == x){
        return size-1;
    }

}

int main(){
    int a[5] = {5,4,5,6,7};
    int ans = last_index(a,5,6);
    cout<<ans<<endl;

}