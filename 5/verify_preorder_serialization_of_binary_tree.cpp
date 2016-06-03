/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false

*/
#include "header.h"

void increase(stack<int>& t){
    if(t.empty()) return;
    int temp = t.top();
    t.pop();
    t.push(temp+1);
}

bool isValidSerialization(string preorder) {
    int len = preorder.length();
    if(len == 0) return true;
    stack<string> s;
    stack<int> t;
    bool first = true;
    stringstream ss(preorder);
    string c;
    while(getline(ss,c,',')){
        if(s.empty() && !first) return false;
        first = false;
        if(c == "#") increase(t);
        else{
            s.push(c);
            t.push(0);
        }
        while(!t.empty() && t.top() == 2){
            t.pop();
            s.pop();
            increase(t);
        }
    }
    return s.empty();
}

int main(){	
	cout<<isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#")<<endl;
    cout<<isValidSerialization("9,#,#,1")<<endl;
    cout<<isValidSerialization("1,#")<<endl;
	return 0;
}
