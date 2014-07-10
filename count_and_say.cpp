#include "header.h"

string count_say(string last){

}

string countAndSay(int n) {
    if(n==1) return "1";
    string last = "1";
    string curr;
    for(int i=1;i<n;i++){
        curr = count_say(last);
        last = curr;
    }
    return curr;
}

int main(){
    string res = countAndSay(5);
    printf("%s\n", res.c_str());
    return 0;
}
