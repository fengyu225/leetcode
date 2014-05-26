#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<stdbool.h>
#include<string>

using namespace std;

//void dfs(string s, int start, vector< vector<string> > &result, vector<string> &temp, int *is_palendrome[]){
//    if(start == s.size()){
//        result.push_back(temp);
//        return ;
//    }
//    for(int i=start; i<s.size(); i++){
//        printf("start: %d, i: %d, is_palendrome[start][i]: %d\n", start, i, is_palendrome[start][i]);
//        if(is_palendrome[start][i]){
//            temp.push_back(s.substr(start,i+1));
//            dfs(s, i+1, result, temp, is_palendrome);
//            temp.pop_back();
//        }
//    }
//}
//
//

bool is_palendrome(string s, int start, int i){
    while(start<i){
        if(s[start] == s[i]){
            start++;
            i--;
        }
        else
            return false;
    }
    return true;
}

void dfs(string s, int start, vector< vector<string> > &result, vector<string> &temp){
    if(start == s.size()){
        result.push_back(temp);
        return ;
    }
    for(int i=start; i<s.size(); i++){
        if(is_palendrome(s, start, i)){
            temp.push_back(s.substr(start,i+1));
            printf("is_palendrome(s,%d,%d): %d, %s\n", start,i,is_palendrome(s, start, i),s.substr(start,i+1).c_str());
            dfs(s, i+1, result, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string> > partition(string s){
    vector< vector<string> > result;
    vector<string> temp;
    dfs(s, 0, result, temp);
    return result;
}

int main(){
   //string s("aab");
   string s("aab");
   vector<vector<string> > r;
   r = partition(s);
   for(int i=0; i<r.size(); i++){
       for(int j=0; j<r[i].size(); j++)
           printf("%s ", r[i][j].c_str());
       printf("\n");
   }
   return 0;
}
