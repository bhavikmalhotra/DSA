#include <iostream>
using namespace std;

class Node{
    public:
    Node *next;         //node type isiloiye kyuki next mei next NODE ka address save hot ah isiliye NMODE TYPE LIYA H
    int data;

    Node(int n){
        next = NULL;
        data = n;
    }
};

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



Node* insertNode(int data, int index, Node *head){
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 0;

    if(index == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    while(temp != NULL && count < index -1 ){
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    return head;
    
}

Node* deleteNode(int index, Node *head){
    Node *temp =  head;
    int count = 0;
    if(index == 0){
        head = head -> next;
        return head;    
    }

    while(temp != NULL && count < index -1){
        temp = temp -> next;
        count++;
    }

    if(temp != NULL){
        Node *a = temp;
        temp  = a -> next;
        a -> next = temp -> next;
    }
    
    return head;

}

Node* insertNodeReursive(int data, int index, Node *head){
    Node *newNode = new Node(data);
    if(head == NULL){                                               //base
        return head;
    }

    if(index == 0){
        newNode -> next = head; 
        head = newNode;
        return head;
    }

    Node *temp = insertNodeReursive(data,index-1,head->next);       //recursion sahi kaam karega
    head -> next = temp;

    return head;
}

Node * deleteNodeRecursive(int index, Node *head){
    if(head == NULL){
        return head;
    }

    if(index == 0){
        head = head -> next;
        return head;
    }

    Node *temp = deleteNodeRecursive(index -1, head -> next);
    head -> next = temp;

    return head;
}

void print_i_th_node(int index,Node *head){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        if(count == index){
            cout<< temp -> data<<endl;
            break;
        }
        temp = temp -> next;
        count++;
    }

}

void middleNode(Node *head){
    int count = 0;
    int mid;
    Node *temp = head;

    while(temp != NULL){
        temp = temp -> next;
        count++;
    }

    if(count % 2 == 0){
        mid = (count-1)/2;
        print_i_th_node(mid,head);
    }else{
        mid = count/2;
        print_i_th_node(mid,head);
    }
    
}



void print(Node<int> *head){

    Node *temp = head;      //head ka address loose nhi karte so we use temp variable
    //although agar yaha head chmage bhi ho jaye agar neeche se phir head pass karenge toh head ki org value milo jaegi kyuki yaha head pass by value hua h not ny refernce
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
    /*
    temp  = head;
    while(temp != NULL){
        cout<<temp -> data<<endl;
        temp = temp -> next;
    }
    */
}

int main(){
    

    Node *head = input();
    middleNode(head);
    //cout<<head2 -> data<<endl;
    //print(head);
    //Node *head2 = insertNodeReursive(99,3,head);
    //Node *head2 = deleteNodeRecursive(1,head);
    //Node *head2 = deleteNode(5,head);
    //print(head2);

    /*
    Node *head2 = insertNode(99,1,head);
    print(head2);
    */
    //STATIC ALLOCATION
    /*
    Node n1(1);
    Node *head = &n1;       //we need to save address of 1st obj somewhere so we store it in heasd
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    */
    /*
    cout<<n1.data<<" "<<n2.data<<endl;
    cout<<head -> data<<endl;

    //DYNAMIC ALLOCATION
    Node *n3 = new Node(1);     //n3 is pointer on stack to the new node dynamically created on the heap
    Node *head = n3;
    Node *n4 = new Node(2);
    n3 -> next = n4;
    */

}