#include <iostream>
using namespace std;

class Polynomial{
    int *data;
    int capacity;
    public:
        Polynomial(){
            data = new int[5];
            for(int i = 0 ; i< 5;i++){
                data[i] = 0;
            }
            capacity = 5;
        } 

        Polynomial(int capacity){
            this-> capacity = capacity;
            this -> data = new int[capacity+1];
            for(int i = 0 ; i< capacity ;i++){
                data[i] = 0;
            }
        }

        Polynomial (Polynomial const &p){
            this -> capacity = p.capacity;
            this -> data = new int[capacity];
            for(int i = 0 ; i< capacity ;i++){
                this->data[i] = p.data[i];
            }
        }

        int setCoefficients(int coeff, int deg){        //n is index at whch we wan tto add
            if(capacity == deg){
                data[deg] = coeff;
                capacity += 1;
                int *newData = new int[capacity];
                for(int i = 0; i< capacity; i++){
                    newData[i] = data[i];
                }
                delete []data;
                data = newData;
            }
            else {
                data[deg] = coeff;
            }
        }

        Polynomial operator+(Polynomial const &d){
            for(int i=0;i<=newcap;i++){
                if(i<=capacity && i<=P2.capacity)
                    P3.data[i]=this->data[i]+P2.data[i];
                else if(i<=capacity)
                    P3.data[i]=this->data[i];
                else 
                    P3.data[i]=P2.data[i];
            }
        
            return P3;

        }

        Polynomial operator-(Polynomial const &P2){
            int newcap=max(this->capacity,P2.capacity);
            Polynomial P3(newcap);     
            for(int i=0;i<=newcap;i++){
                if(i<=capacity && i<=P2.capacity)
                    P3.data[i]=this->data[i]-P2.data[i];
                else if(i<=capacity)
                    P3.data[i]=this->data[i];
                else 
                    P3.data[i]=-P2.data[i];
            }  
            return P3;
        }

        Polynomial operator*(Polynomial const &P2){
            int newcap=this->capacity+P2.capacity;
            Polynomial P3(newcap);           
            for(int i=0;i<=this->capacity;i++){   
                for(int j=0;j<=P2.capacity;j++){
                    P3.data[i+j]+=this->data[i]*P2.data[j];
                }
            }
            return P3;
        }

        void operator=(Polynomial const &p){
            int *newdeg=new int[p.capacity+1];
            //Copy the contents
            for(int i=0;i<p.capacity;i++)
                newdeg[i]=p.data[i];
                
            
            this->data=newdeg;  
            this->capacity=p.capacity;
        }

        void print(){
            for(int i = 0; i < capacity; i++){
                if(data[i] != 0){
                    cout<<data[i]<<"x"<<" ";
                }
            }
            cout<<endl;
        }

};

int main(){
    Polynomial p1;
    p1.setCoefficients(2,2);
    p1.setCoefficients(23,0);
    p1.print();
    Polynomial p2(p1);
    p2.print();

}