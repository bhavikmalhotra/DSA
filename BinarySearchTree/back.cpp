#include <iostream>
#include <queue>
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

BinaryTree<int> *binarySearchNode(BinaryTree<int> *root,int search){
    int rootData = root->data;
    if(rootData == search){
        return root;
    }

    if(search < rootData){
        BinaryTree<int> *leftChild = binarySearchNode();
        
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

void range(BinaryTree<int> *root, int start,int end){
    int rootData = root->data;

    if(root == NULL){
        return 0;
    }
    if(start < rootData){
        range(root->left,start,end);
    }
    if(start <= rootData && end >=rootData){
        cout<<root->data<<" ";
    }
    if(start > rootData){
        range(root->right,star,end);
    }

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
        if(rightdChildData != -1){
            BinaryTree<int> *rightChild = new BinaryTree<int>(rightChildData);
            q.push(rightChild);
            front->right=rightChild;
        }
    }
    return root;
}

int main(){

}