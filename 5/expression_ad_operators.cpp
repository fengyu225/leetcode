/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add operators +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

// 3:24
#include "header.h"

//void search(string& num, int l, int r, unordered_map<string,int>& m){
//    if(l>r) return;
//    if(l == r){
//        m[num.substr(l, 1)] = num[l]-'0';
//        return;
//    }
//    for(int i=l; i<r; i++){
//        unordered_map<string,int> l_m;
//        unordered_map<string,int> r_m;
//        search(num, l, i, l_m);
//        search(num, i+1, r, r_m);
//        for(auto l_i:l_m){
//            for(auto r_i:r_m){
//                m[l_i.first+"+"+r_i.first] = l_i.second+r_i.second;
//                m[l_i.first+"-"+r_i.first] = l_i.second-r_i.second;
//                m[l_i.first+"*"+r_i.first] = l_i.second*r_i.second;
//            }
//        }
//    }
//}
//
//vector<string> addOperators(string num, int target) {
//    int sz = num.length();
//    if(sz == 1) return num[0]-'0' == target?vector<string>(1, num):vector<string>(); 
//    unordered_map<string,int> m;
//    search(num, 0, sz-1, m);
//    vector<string> res;
//    for(auto i:m) if(i.second == target) res.push_back(i.first);
//    return res;
//}

//void print_map(unordered_map<string,int>& m){
//    cout<<endl;
//    cout<<"===================="<<endl;
//    for(auto i:m) cout<<i.first<<"->"<<i.second<<endl;
//    cout<<"===================="<<endl;
//    cout<<endl;
//}

///vector<string> addOperators(string num, int target) {
///    int sz = num.length();
///    if(sz == 0) return vector<string>();
///    if(sz == 1) return num[0]-'0' == target?vector<string>(1, num):vector<string>(); 
///    vector<vector<unordered_map<string,int>* > > arr(sz+1, vector<unordered_map<string,int>* >(sz, NULL));
///    for(int i=1; i<=sz; i++){ //i is length
///        for(int j=0; j+i<=sz; j++){
///            unordered_map<string,int>* m = new unordered_map<string,int>();
///            if(i == 1){
///                (*m)[num.substr(j, 1)] = num[j]-'0';
///                arr[i][j] = m;
///            }
///            else{
///                unordered_map<string,int>* l_m, *r_m;
///                for(int k=1; k<i; k++){
///                    cout<<i<<" "<<j<<" "<<k<<endl;
///                    l_m = arr[k][j];
///                    r_m = arr[i-k][j+k];
///                    for(auto left:(*l_m)){
///                        for(auto right:(*r_m)){
///                            (*m)[left.first+"+"+right.first] = left.second+right.second;
///                            if(right.first.length() == 1 || right.first[1] != '-')
///                                (*m)[left.first+"-"+right.first] = left.second-right.second;
///                            if(!(left.first.length() > 1 && right.first.length() > 1 && left.first[left.first.length()-2] != '*' && right.first[1] != '*' || left.first.length() == 1 && right.first.length()>1 && right.first[1] != '*' || left.first.length()>1 && right.first.length() == 1 && left.first[left.first.length()-2] != '*')){
///                                (*m)[left.first+"*"+right.first] = left.second*right.second;
///                                cout<<"adding: "<<left.first+"*"+right.first<<"->"<<left.second*right.second<<endl;
///                            }
///                                //print_map(*m);
///                        }
///                    }
///                }
///                arr[i][j] = m;
///            }
///        }
///    }
///    vector<string> res;
///    for(auto i: *arr[sz][0]) if(i.second == target) res.push_back(i.first);
///    return res;
///}

int main(){
    //vector<string> res = addOperators("123", 6);
    //vector<string> res = addOperators("00", 0);
    //vector<string> res = addOperators("2147483647", 2147483647);
    //vector<string> res = addOperators("1000000009", 9);
    //vector<string> res = addOperators("232", 8);
    vector<string> res = addOperators("123456789", 45);
    print_vector<string>(res);
    return 0;
}