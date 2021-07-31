#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//binary search tree
//similar to binary search algorithm

template <typename T>
class BinaryTree{
    public:
        T data;
        BinaryTree<T> *left;
        BinaryTree<T> *right;
    BinaryTree(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTree(){
        delete left;
        delete right;
    }
};

template <typename T>
class Node{
    public:
    Node<T> *next;         
    T data;

    Node(T n){
        next = NULL;
        data = n;
    }
};

BinaryTree<int> *binarySearchNode(BinaryTree<int> *root,int search){
    if(root == NULL){
        return NULL;
    }

    int rootData = root->data;
    if(rootData == search){
        return root;
    }

    if(search < rootData){
        BinaryTree<int> *leftChild = binarySearchNode(root->left,search);
    }else{
        BinaryTree<int> *rightChild = binarySearchNode(root->right,search);
    }

    //cout<<"Not Found"<<endl;
    //return 0;

}

void printTreeLevelWise(BinaryTree<int> *root){
    queue<BinaryTree<int> *> q;
    q.push(root);
    while(q.size()!=0){
        BinaryTree<int> *front = q.front();
        q.pop();
        cout<<front->data<<": ";
  
        if(front->left != NULL){
            cout<<"L="<<front->left->data<<" ";
            q.push(front->left);
        }

        if(front->right != NULL){
            cout<<"R="<<front->right->data<<" ";
            q.push(front->right);
        }
        cout<<endl;
    }
}
void printInGivenRange(BinaryTree<int> *root, int start,int end){
    

    if(root == NULL){
        return;
    }

    if(start <= root->data && end >=root->data){
        cout<<root->data<<" ";
    }
    if(start < root->data){
        printInGivenRange(root->left,start,end);
    }
    if(end >= root->data){
        printInGivenRange(root->right,start,end);
    }

}

int smallest(BinaryTree<int> *root){
    int min = 0 ;
    if(root == NULL){
        return 0;
    }
    min == root->data;

    int leftSmall = smallest(root -> left);
    int rightSmall = smallest(root ->right);

    int minofSubTree = std::min(leftSmall,rightSmall);
    if(min <= minofSubTree){
        return min;
    }else{
        return minofSubTree;
    }
}

int minimum(BinaryTree<int> *root){
    if(root == NULL){
        return INT_MIN;
    }
    return min(root->data ,min(minimum(root->left),minimum(root->right)));
}

int maximum(BinaryTree<int> *root){
    if(root == NULL){
        return INT_MAX;
    }
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}

bool isBST(BinaryTree<int> *root){
    if(root == NULL){
        return true;
    }
    
    if((root->data > maximum(root->left)) && (root->data <= minimum(root->right)) && isBST(root->left) && isBST(root->right) ){
        return true;
    }else{
        return false;
    }
}// ye wala algo is not good because we need 3 outputs aur hum baar baar call karre h isse acha ek class banale aur ek hi baar vo 3 kaam karle

class isBSTreturn{
    public:
        int maximum;
        int minimum;
        bool isBST;
};

isBSTreturn isBSTbetter(BinaryTree<int> *root){
    if(root == NULL){
        isBSTreturn output;
        output.maximum = INT_MAX;
        output.minimum = INT_MIN;
        output.isBST = true;
        return output;
    }

    isBSTreturn leftOutput = isBSTbetter(root->left);
    isBSTreturn rightOutput = isBSTbetter(root->right);
    //(root->data > maximum(root->left)) && (root->data <= minimum(root->right)) && isBST(root->left) && isBST(root->right)
    int maximum = max(root->data, max(leftOutput.maximum,rightOutput.maximum));
    int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    bool output = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    isBSTreturn finalOutput;
    finalOutput.maximum = maximum;
    finalOutput.minimum = minimum;
    finalOutput.isBST = output;
    return finalOutput;
}

bool isBST3(BinaryTree<int> *root,int max = INT_MAX, int min = INT_MIN){
    if(root == NULL){
        return true;
    }
    if(root->data > max || root->data < min){
        return false;
    }
    bool isLeftOk = isBST3(root->left,root->data-1,min);
    bool isRightOk = isBST3(root->right,max,root->data);
    return isLeftOk && isRightOk;
}
class Base{
    public:
        Node<int> *head;
        Node<int> *tail;
        Base(){
            head = NULL;
            tail = NULL;
        }
};

Base linkedlistUsingBST(BinaryTree<int> *root){
    Base combinedlist;
    if(root == NULL){
        return combinedlist;
    }
    
    Base lefttree = linkedlistUsingBST(root->left);
    Base righttree = linkedlistUsingBST(root->right);
    Node<int> *newNode = new Node<int>(root->data);

    if(lefttree.tail != NULL){
        lefttree.tail->next = newNode;
    }
    newNode->next = righttree.head;

    if(lefttree.head != NULL){
        combinedlist.head = lefttree.head;
    }else{
        combinedlist.head = newNode;
    }
    

    if(righttree.tail != NULL){
        combinedlist.tail=righttree.tail;
    }else{
        combinedlist.tail = newNode;
    }
    return combinedlist;
}


BinaryTree<int> *binaryTreeFromSortedArray(int arr[] , int startIndex, int endIndex){
    if (startIndex > endIndex){
        return NULL;
    }
        
    int middle = (startIndex+endIndex)/2;

    BinaryTree<int> *root = new BinaryTree<int>(arr[middle]);

    BinaryTree<int> *leftTree = binaryTreeFromSortedArray(arr, startIndex,middle-1);
    BinaryTree<int> *rightTree = binaryTreeFromSortedArray(arr,middle+1,endIndex);
    root->left = leftTree;
    root->right = rightTree;

    return root;

}

BinaryTree<int> *takeINputLevelWise(){
    int rootData;
    cout<<"Enter root Data: "<<endl;
    cin>>rootData;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    if(rootData == -1){
        return NULL;
    }
    
    queue<BinaryTree<int>* > q;
    q.push(root);

    while(q.size()!=0){
        BinaryTree<int>* front = q.front();
        q.pop();

        //left mei data enter karne ke liye
        int leftChildData;
        cout<<"Enter Left Child of "<<front->data<<" : "<<endl;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTree<int> *leftChild = new BinaryTree<int>(leftChildData);
            q.push(leftChild);
            front->left=leftChild;
        }

        //right mei data enter karne ke liye
        int rightChildData;
        cout<<"Enter Right Child of "<<front->data<<" : "<<endl;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTree<int> *rightChild = new BinaryTree<int>(rightChildData);
            q.push(rightChild);
            front->right=rightChild;
        }
    }
    return root;
}

vector<int> *pathToNode(BinaryTree<int> *root, int data){
    if(root == NULL){
        return NULL;
    }

    

    if(root->data == data){
        vector<int> *out = new vector<int>();
        out->push_back(root->data);
        return out;
    }
    
    vector<int> *leftpath = pathToNode(root->left,data);
    if(leftpath != NULL){
        leftpath->push_back(root->data);
        return leftpath;
    }

    vector<int> *rightpath = pathToNode(root->right,data);
    if(rightpath != NULL){
        rightpath->push_back(root->data);
        return rightpath;
    }else{
        return NULL;
    }

    


}


void print(Node<int> *head){
    if(head == NULL){
        return;
    }
    Node<int> *temp = head;      
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
  
    BinaryTree<int> *root = takeINputLevelWise();
    printTreeLevelWise(root);
    vector<int> *path = pathToNode(root,6);
    for(int i = 0; i < path->size();i++){
        cout<<"<"<<path->at(i)<<">";
    }
    /*
    Base list = linkedlistUsingBST(root);
    print(list.head);
    int p[]={2,3,4,5,6,7,8};
    BinaryTree<int> *root = binaryTreeFromSortedArray(p,0,6);
    printTreeLevelWise(root);
    int s;
    cin>>s;
    BinaryTree<int> *element = binarySearchNode(root,s);
    cout<<element->data;
    //BinaryTree<int> *root = takeINputLevelWise();
    //printTreeLevelWise(root);
    //cout<<isBST3(root);
    //delete root;
    */
    //printInGivenRange(root,4,6);
  
    //cout<<isBSTbetter(root).isBST;
    delete root;
    delete path;
    
}
//5 3 7 2 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1 

//1 3 7 2 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1