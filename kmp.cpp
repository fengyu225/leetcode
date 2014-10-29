#include "header.h"

vector<int> preprocess(char* p){
    int size = strlen(p);
    int len = 0;
    vector<int> lps(size,0);
    for(int i=1; i<size; i++){
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
        }
        else{
            while(len>0 && p[len] != p[i]) len = lps[len-1];
            if(len == 0)
                lps[i] = 0;
            else{
                len++;
                lps[i] = len;
            }
        }
    }
    return lps;
}

void search(char* s, char* p){
    int s_sz = strlen(s);
    int p_sz = strlen(p);
    vector<int> lps = preprocess(p);
    int i=0,j=0;
    while(i<s_sz){
        if(j==p_sz){
            cout<<"match at: "<<i-j<<endl;
            j = lps[j-1];
            continue;
        }
        if(s[i] == p[j]){
            i++;
            j++;
        }
        else{
            if(j == 0)
                i++;
            else
                j = lps[j-1];
        }
    }
}

int main(){
    char s[] = "ABABABCABABACBCABABABC";
    char p[] = "ABABAC";
    search(s,p);
    cout<<endl;
    return 0;
}
