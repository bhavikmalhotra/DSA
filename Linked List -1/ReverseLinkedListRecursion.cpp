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

bool isPalindromeHelper(Node *head, Node *tail){
    if(head == NULL){
        return true;
    }

    if(head->data == tail->data){
        return true;
    }else{
        return false;
    }

    Node *newTail = head;
    while(newTail->next != tail){
        newTail = newTail->next;
    }

    bool out = isPalindromeHelper(head->next,newTail);
    return out;
}

bool isPalindrome(Node *head){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    //cout<<"hello";
    //cout<<temp->data;
    //cout<<temp->next;
    bool out = isPalindromeHelper(head,temp);
    return out;
}

Node *Reverse(Node * head){
    if(head == NULL){                                  
        return NULL;                                            
    }
    if(head -> next == NULL){
        return head;
    }

    Node *revHead = Reverse(head -> next);  

    Node *tempRevHead = revHead;
    while(tempRevHead -> next != NULL){
        tempRevHead = tempRevHead -> next;
    }
    tempRevHead -> next = head;
    head -> next = NULL;
    return revHead;
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
            tail -> next = newNode;     //tail abhi starting mei h uske next mei humne naye node ke address daalke link kardiya.
            tail = newNode;             //or tail = tail -> data rtail ke data mei agle ka ddress pada hua h na toh agle par shift ho jaega ye use karke.
       }
        
        cin>>data;
    }
    return head;
}

void print(Node *head){

    Node *temp = head;      
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main(){
    Node *head = input();
    print(head);
    cout<<isPalindrome(head);
    //head = Reverse(head);
    //print(head);
    //Node *head2 = Reverse(head);
    //print(head2);
    //return 0;

}



 