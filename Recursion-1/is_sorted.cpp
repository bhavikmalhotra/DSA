#include <iostream>
using namespace std;

bool is_soreted(int a[],int size){
    if(size == 0 || size == 1){     //base
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }

    int is_smallArray = is_soreted(a+1,size-1);
    return is_smallArray;

}

int main(){
    int a[100];
    for(int i = 0; i< 10;i++){
        cin>>a[i];
    }
    cout<<is_soreted(a,10);
}