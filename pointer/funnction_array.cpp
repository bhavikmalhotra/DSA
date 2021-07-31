#include <iostream>
using namespace std;

//array as a pointer hi pass hota h function mei
//arrays ko jab pass karte h toh vo effectively pointer ki tarsh hi pass hote h.

int sum(int *a, int size){//pointer ki tarach pass hota h isiliye * liya h normal array bhi likhte tab bhi yahi aata
    int ans = 0;
    cout<< sizeof(a) <<endl;//pointer ka size print hoga
    //thus we can treat array as pointer and use this loop tp find the sum of elements.
    for(int i = 0; i<size ; i++){
        ans += a[i];
    }
    return(ans);

}
int main(){
    int arr[10];
    cout<< sizeof(arr) <<endl;//yaha array ka size print hoga aur array as a pointer pass hota h upar function mei
    cout<< sum(arr,10) <<endl;
    cout<< sum(arr+3,10) <<endl;//we can pass part of an array too using this method
    
}
