#include <string>
using namespace std;
class TrieNode{
    public:
        char data;
        //hummen trienode * ka address store karna h adday mei thus **
        TrieNode **children; //*childeren holds address of type trieNode *
        bool isTerminal;

        TrieNode(char data){
            this -> data = data;
            children = new TrieNode*[26];       //*children ek pointer variable h jo hold karra h *int type ke variab;le ko int **child= new int*[26];
            for(int i = 0 ; i<26 ; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    TrieNode *root;
    public:
        Trie(){
            root = new TrieNode('\0');
        }
        void insertHelper(TrieNode *root, string s){

            //base case
            if(s.size() == 0){
                root -> isTerminal = true;
                return;
            }

            //small calculation
            int index = s[0] - 'a';
            TrieNode *child;
            if(root->children[index] != NULL){
                child = root->children[index];
            }else{
                child = new TrieNode(s[0]);
                root->children[index] = child;
            }

            //recursion
            insertHelper(child,s.substr(1));
           
        }

        void insert(string word){
            insertHelper(root,word);
        }

        bool searchHelper(TrieNode *root, string s){
            //base
            if(s.size() == 0){
                return root->isTerminal;
            }

            //small
            int index = s[0] -'a';
            TrieNode *child;
            if(root->children[index] != NULL){
                child = root->children[index];
            }else{
                return false;
            }

            return searchHelper(child, s.substr(1));
        }
        bool search(string word){
            return searchHelper(root,word);
        }

        void removeHelper(TrieNode *root , string s){
            if(s.size() == 0){
                root->isTerminal = false;
                return;
            }
            int index = s[0] - 'a';
            TrieNode *child;
            if(root->children[index]!=NULL){
                child = root->children[index];
            }else{
                return;
            }
            removeHelper(child,s.substr(1));

            //remove child if useless:
            if(child->isTerminal == false){
                for(int i = 0 ; i<27; i++){
                    if(child->children[index] != NULL){
                        return;
                    }
                }
                delete child;
                root -> children[index] = NULL;
            }


        }

        void removeWord(string word){
            removeHelper(root,word);
        }

};