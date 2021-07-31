#include <iostream>
using namespace std;

void inplaceHeapSort(int *pq,int n){
    //build heap in input array
    for(int i = 1 ; i<n ; i++){
        //upheapify
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex]){
   int temp = pq[childIndex];
   pq[childIndex] = pq[parentIndex];       
   pq[parentIndex] = temp; 
            }else{
   break;
            }
            childIndex = parentIndex;
        }
    }

    //remove elements
    int size = n;
    while(size >1 ){
        int temp = pq[0];
        pq[0]=pq[size-1];
        pq[size -1] = temp;
        size--;

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        while(leftChildIndex < size){
            int minINdex=parentIndex;
            if(pq[minINdex]>pq[leftChildIndex]){
                minINdex = leftChildIndex;
            }
            if(pq[minINdex]>pq[rightChildIndex] && rightChildIndex < size){
                minINdex= rightChildIndex;
            }
            if(minINdex == parentIndex){
                break;
            }

            int temp = pq[minINdex];
            pq[minINdex] = pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex= minINdex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
    }
}

int main(){
    int input[] = {5,2,0,8,1};
    inplaceHeapSort(input,5);
    for(int i = 0; i<5;i++){
        cout<<input[i]<<" ";
    }

}
