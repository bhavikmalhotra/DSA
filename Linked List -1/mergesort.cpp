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

Node *mergeSort(Node * head,int mid){
    int mid,count = 0;
    Node *temp = head;
    while(temp != NULL){
        temp -> temp -> next;
        count++;
    }

    if (coount %2 ==0){
        mid = count/2;
    }else{
        mid = (count-1)/2;
    }

    Node *firsthalf = head;

    Node *head1 = mergeSort(head ,mid)48

}
void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
 
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
 
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

Node *merge()

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

void print(Node *head){

    Node *temp = head;     
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node *head1 = input();
    Node *head2 = input();
    print(head1);
    print(head2);
    Node *merged = merge2Nodes(head1,head2);
    print(merged);
}