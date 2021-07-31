#include <iostream>
using namespace std;

class DynamicArray{
    int capacity;
    int *data;
    int nextIndex;
    
    public:

        DynamicArray(){
            data = new int[5];
            nextIndex = 0;
            capacity = 5;
        }

        DynamicArray(DynamicArray const &d){
            //shallow copy
            //this -> data = d.data;

            //deep copy
            this -> data = new int[d.capacity];
            for(int i = 0 ; i < d.nextIndex; i++){
                this -> data[i] = d.data[i];
            }
            this -> capacity = d.capacity;
            this -> nextIndex = d.nextIndex;
        }

        DynamicArray operator=(DynamicArray const &d){
            this -> data = new int[d.capacity];
            for(int i = 0 ; i < d.nextIndex; i++){
                this -> data[i] = d.data[i];
            }
            this -> capacity = d.capacity;
            this -> nextIndex = d.nextIndex;
        }

        void add(int a){
            if(nextIndex == capacity){
                capacity *= 2;
                int *newData = new int[capacity];
                for(int i = 0; i< capacity; i++){
                    newData[i] = data[i];
                }
                delete []data;
                data = newData;
            }
            data[nextIndex] = a;
            nextIndex++;
        }

        int getElements(int i){
            if(i<nextIndex){
                return data[i];
            }
            else{
                return -1;
            }

        }

        int replaceElement(int a, int index){
            if(index < nextIndex){
                data[index] = a;
            }
            else if(index == nextIndex){
                add(a);
            }
            else{
                return -1;
            }
        }

        void print(){
            for(int i = 0; i<nextIndex; i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.add(70);

    d1.print();

    DynamicArray d2(d1); //copy cons does shallow copy by default so we will make our own copy cons
    d1.replaceElement(11,0);
    d1.print();
    d2.print();

    DynamicArray d3;
    d3 = d2;
    d2.replaceElement(13,3);
    d2.print();
    d3.print();
}