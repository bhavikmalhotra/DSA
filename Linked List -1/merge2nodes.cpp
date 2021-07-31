#include <iostream>
using namespace std;

class Node{
    public:
    Node *next;         
    int data;

    Node(int n){
        next = NULL;
        data = n;
    }
};



Node *merge2Nodes(Node *h1,Node *h2){
    if (h1 == NULL){
        return h2;
    }else if(h2 == NULL){
        return h1;
    }

   Node *fh = NULL;
   Node *ft = NULL; 

   while(h1 != NULL && h2 != NULL){
        if(h1 -> data < h2 -> data){
            if(fh == NULL){
                fh = h1;
                ft = h1;
            }else{
                ft -> next = h1;
                ft = ft -> next;
            }
        h1 = h1 -> next;
        }else{
            if(fh == NULL){
                fh = h1;
                ft = h1;
            }else{
                ft -> next = h2;
                ft = ft -> next;
            }
        h2 = h2 -> next;
        }
    }
  
    if(h1 != NULL && h2 == NULL){
        ft -> next = h1;
    } 

    if(h2 != NULL && h1 == NULL){
        ft -> next = h2;
    }

    return fh;
}

Node* input(){
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cin>>data;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
       else{
            tail -> next = newNode;    
            tail = newNode;             
       }
        
        cin>>data;
    }
    return head;
}

Node* input(){
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cin>>data;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        /*  bekar algo time complexity bekar h we will use tail
        else{
            Node *temp = head;          //yaha par ek node type ka head abna hua h jisme next aur data stored hai jo humne temp mei copy kiya abhi
            while(temp -> next != NULL){        //agar uss temp ke next ki value null hai toh humme linbk karfne h dono node so-------------------------|
                temp = temp -> next;            //agar temp ke next ki value null nhi h toh temp ki value chnage kar denge aur next ki                  |
            }                                  //value de demnge jab tak usse null nhi milta                                                            |           
            temp -> next = newNode;             //agar nu;ll h toh toh uss temp ke next mei naya jo node banaya h uska address daalke link kardo <------|             
        }
        */
       else{
            tail -> next = newNode;     //tail abhi starting mei h uske next mei humne naye node ke address daalke link kardiya.
            tail = newNode;             //or tail = tail -> data rtail ke data mei agle ka ddress pada hua h na toh agle par shift ho jaega ye use karke.
       }
        
        cin>>data;
    }
    return head;
}

int main(){
    Node *head1 = input();
    Node *head2 = input();
    print(head1);
    print(head2);
    Node *merged = merge2Nodes(head1,head2);
    print(merged);
}
