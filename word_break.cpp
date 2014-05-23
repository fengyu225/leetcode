/*
 *  Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 *  For example, given
 *  s = "leetcode",
 *  dict = ["leet", "code"].
 *
 *  Return true because "leetcode" can be segmented as "leet code". 
 */

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct node {
    char c;
    struct node* children[26] = {NULL};
};

void add_word(char* s, struct node* root){
    struct node* curr = root;
    while(*s){
        if(curr->children[*s-'a'] == NULL)
            curr->children[*s-'a'] = (struct node*)malloc(sizeof(struct node));
        curr = curr->children[*s-'a'];
        s++;
    }
}

bool in_dict(char* s, struct node* root){
    while(*s){
        if(!root || !root->children[*s-'a']) return false;
        root = root->children[*s-'a'];
        s++;
    }
    for(int i=0; i<26; i++)
        if(root->children[i]) return false;
    return true;
}

bool word_break(char* s, struct node* root){
    if(in_dict(s,root)) return true;
    for(int i=1; i<strlen(s); i++){
        char* front = (char*)malloc(sizeof(char)*(i+1));
        for(int j=0; j<i; j++)
            front[j] = s[j];
        front[i] = '\0';
        if(in_dict(front,root) && word_break(s+i, root))
            return true;
    }
    return false;
}

int main(){
    struct node root;
    root.c = ' ';
    add_word("leet", &root);
    add_word("code", &root);
    bool r;
    r = word_break("leetcode", &root);
    printf("%s\n", r?"true":"false"); 
    r = word_break("leetode", &root);
    printf("%s\n", r?"true":"false"); 
    r = word_break("leetleetcode", &root);
    printf("%s\n", r?"true":"false"); 
    return 0;
}
