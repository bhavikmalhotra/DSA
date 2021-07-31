#include <iostream>
using namespace std;

//RECURSIOMN
//1>> BASE CASE
//2>> RECURSIVE CALL
//3>> SMALL CALCULATION


int first_index(int a[],int size, int x){ 
    if(size == 0 ){
        return -1;
    }
    if(a[0] == x){
        return 0;
    }
    int small_array_index = first_index(a + 1,size - 1,x);
    if(small_array_index == -1){
        return -1;
    }else{
        return small_array_index+1;
    }
}

int main(){
    

}