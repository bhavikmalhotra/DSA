#include <iostream>
#include "tries.h"
using namespace std;

int main(){
    Trie t;
    t.insert("and");
    t.insert("art");
    t.insert("hell");

    cout<<t.search("hell")<<endl;
    t.removeWord("art");
    cout<<t.search("art");
    cout<<t.search("hello");

}