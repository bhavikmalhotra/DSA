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
}