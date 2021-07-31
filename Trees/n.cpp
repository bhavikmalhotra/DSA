#include<queue>
void printLevelWise(TreeNode<int>* root) {
    if(root==NULL){
        return;
    }
    queue<TreeNode<int>*> q;
    while(q.size()!=0){
        TreeNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<":";
        for(int i = 0 ; i<front->children.size();i++){
                if(i<front->children.size()-1){
                  cout<<front->children[i]->data<<",";}
                 else{
cout<<front->children[i]->data;}        
        q.push(front->children[i]);
        }
        
    }
    cout<<endl;
    
}