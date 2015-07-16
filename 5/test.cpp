#include "header.h"

int main(){
    Trie trie;
    trie.insert("something");
    cout<<trie.search("key")<<endl;
    cout<<trie.search("something")<<endl;
    return 0;
}