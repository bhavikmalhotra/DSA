#include <iostream>
#include <queue>
using namespace std;

void kSmallestElements(int input[],int n,int k){
    priority_queue<int> pq;
    for(int i = 0;i < k;i++){
        pq.push(input[i]);
    }
    for(int i = k;i<n;i++){
        if(pq.top()>input[k]){
            pq.pop();
            pq.push(input[i]);

        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }


}
int main(){
    int input[]={1,12,6,7,9};
    kSmallestElements(input,5,3);

}