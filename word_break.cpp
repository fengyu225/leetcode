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

bool in_dict(char* s, char* e, struct node* root){
    if(s>e)
        return false;
    char* temp = (char*)malloc(sizeof(char)*(e-s+2));
    char* o = temp;
    for(char* c=s;c<=e;c++,temp++) *temp=*c;
    *temp='\0';
    bool r = in_dict(o,root);
    free(o);
    return r;
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

bool word_break_dp(char* s, struct node* root){
    bool d[100] = {false};
    d[0] = true;
    d[1] = in_dict(s,s,root)?true:false;
    for(int i=2; i<=strlen(s); i++){
        bool r = false;
        for(int j=1; j<i; j++)
            if(d[j] && in_dict(s+j, s+i-1, root)){
                r = true;
                break;
            }
        d[i] = r || in_dict(s, s+i-1, root);
    }
    return d[strlen(s)];
}

int main(){
    struct node root;
    root.c = ' ';
    add_word("leet", &root);
    add_word("code", &root);
    bool r;
    r = word_break_dp("leetcode", &root);
    printf("%s\n", r?"true":"false"); 
    r = word_break_dp("leetode", &root);
    printf("%s\n", r?"true":"false"); 
    r = word_break_dp("leetleetcode", &root);
    printf("%s\n", r?"true":"false"); 
    return 0;
}
