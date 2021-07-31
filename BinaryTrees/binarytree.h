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
}