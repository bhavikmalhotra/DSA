#include <iostream>
#include <queue>
using namespace std;

//binary tree mein 2 hi option hite h ya toh 0,1,2 thus we can have only left and right trees max in binary tree

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

//1 2 3 4 5 6 -1 -1 -1 7 8 -1 -1 -1 -1 -1 -1 
int height(BinaryTree<int> *root){
    int ans =1;
    if(root == NULL){
        return 0;
    }
    return ans + height(root->left) + height(root->right);
}

int diameter(BinaryTree<int> *root){
    if(root == NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1 , max(option2, option3));
    
}

pair<int,int> heightDiameter(BinaryTree<int> *root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second =  0;
        return p;
    }

    pair<int,int> left = heightDiameter(root->left);
    pair<int,int> right = heightDiameter(root->right);
    int lh = left.first;
    int ld = left.second;
    int rh = right.first;
    int rd = right.second;
    int h = 1+ max(lh ,rh);
    int dia = max(lh+rh, max(rd,ld));
    pair<int,int> ans;
    ans.first = h;
    ans.second = dia;
    return ans;
}



BinaryTree<int> *buildTreeHelper(int *prO,int *inO, int prS,int prE,int inS,int inE){
    if(inS>inE){
        return NULL;
    }

    BinaryTree<int> *root = new BinaryTree<int>(prO[prS]);
    int rootIndex = -1;

    for(int i = 0; i <= prE ;i++){
        if(inO[i] == prO[prS]){
            rootIndex = i;
            break;
        }
    }
    int lprS = prS + 1;
    int lInS = inS;
    int lInE = rootIndex -1;
    int rprE = prE;
    int rInS = rootIndex + 1                                                                  ;
    int rInE = inE;
    int lprE = lInE - lInS + lprS;
    int rprS = lprE + 1;
   
    BinaryTree<int> *le = buildTreeHelper(prO , inO, lprS, lprE, lInS, lInE);
    BinaryTree<int> *ri  = buildTreeHelper(prO , inO, rprS, rprE, rInS, rInE);
    root->left = le;
    root->right = ri;
    return root;

}

BinaryTree<int> *buildTree(int *preOrder, int *InOrder,int size){
    return buildTreeHelper(preOrder,InOrder,0,size-1,0,size-1);
}

BinaryTree<int>* takeInput(){
    int rootData;
    cout<<"Enter Data: "<<endl;
    cin>>rootData;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    if(rootData == -1){
        return NULL;
    }
    BinaryTree<int> *leftChild = takeInput();
    BinaryTree<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;

}

int numOfNodes(BinaryTree<int> *root){
    if(root == NULL){
        return 0;
    }
    int ans=1;
    int leftNode = numOfNodes(root->left);
    int rightNodes = numOfNodes(root->right);
    return ans+leftNode+rightNodes;
}

void preOrder(BinaryTree<int> *root){
    if(root == NULL){
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";

}

void postOrder(BinaryTree<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    postOrder(root->left);
    postOrder(root->right);

}

void inOrder(BinaryTree<int> *root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


void printTreeLevelWise(BinaryTree<int> *root){
    queue<BinaryTree<int> *> q;
    q.push(root);
    while(q.size()!=0){
        BinaryTree<int> *front = q.front();
        q.pop();
        cout<<front->data<<": ";
        //if(front->left->data != -1){
        if(front->left != NULL){
            cout<<"L="<<front->left->data<<" ";
            q.push(front->left);
        }
        //if(front->right->data != -1){
        if(front->right != NULL){
            cout<<"R="<<front->right->data<<" ";
            q.push(front->right);
        }
        cout<<endl;
    }
}

void printTree(BinaryTree<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL){
        cout<<"L="<<root->left->data<<" ";
    }

    if(root ->right != NULL){
        cout<<"R="<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
    
}
//1 2 -1 -1 3 -1 -1

int main(){
    /*
    BinaryTree<int> *root = new BinaryTree<int>(1);
    BinaryTree<int> *node1 = new BinaryTree<int>(2);
    BinaryTree<int> *node2 = new BinaryTree<int>(3);

    root->left = node1;
    root->right = node2;
    
   int pr[] = {1,2,4,5,3,6,8,9,7};
   int in[] = {4,2,5,1,8,6,9,3,7};
   BinaryTree<int> *root = buildTree(pr,in,9);
   printTreeLevelWise(root);
   cout<<diameter(root);

   */

    BinaryTree<int> *root = takeINputLevelWise();
    printTreeLevelWise(root);
    pair<int,int> p = heightDiameter(root);
    cout<<p.first<<endl;
    cout<<p.second<<endl;

    /*
    cout<<numOfNodes(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    */

}