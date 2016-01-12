/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

#include "header.h"

vector<vector<string> > groupStrings(vector<string>& strings) {
    vector<vector<string> > res;

    return res;
}

/*
["fpbnsbrkbcyzdmmmoisaa", "cpjtwqcdwbldwwrryuclcngw", "a", "fnuqwejouqzrif", "js", "qcpr", "zghmdiaqmfelr", "iedda", "l", "dgwlvcyubde", "lpt", "qzq", "zkddvitlk", "xbogegswmad", "mkndeyrh", "llofdjckor", "lebzshcb", "firomjjlidqpsdeqyn", "dclpiqbypjpfafukqmjnjg", "lbpabjpcmkyivbtgdwhzlxa", "wmalmuanxvjtgmerohskwil", "yxgkdlwtkekavapflheieb", "oraxvssurmzybmnzhw", "ohecvkfe", "kknecibjnq", "wuxnoibr", "gkxpnpbfvjm", "lwpphufxw", "sbs", "txb", "ilbqahdzgij", "i", "zvuur", "yfglchzpledkq", "eqdf", "nw", "aiplrzejplumda", "d", "huoybvhibgqibbwwdzhqhslb", "rbnzendwnoklpyyyauemm"]


[["a","d","i","l"],["eqdf","qcpr"],["lpt","txb"],["yfglchzpledkq","zghmdiaqmfelr"],["kknecibjnq","llofdjckor"],["cpjtwqcdwbldwwrryuclcngw","huoybvhibgqibbwwdzhqhslb"],["lbpabjpcmkyivbtgdwhzlxa","wmalmuanxvjtgmerohskwil"],["iedda","zvuur"],["js","nw"],["lebzshcb","ohecvkfe"],["dgwlvcyubde","ilbqahdzgij"],["lwpphufxw","zkddvitlk"],["qzq","sbs"],["dclpiqbypjpfafukqmjnjg","yxgkdlwtkekavapflheieb"],["mkndeyrh","wuxnoibr"],["firomjjlidqpsdeqyn","oraxvssurmzybmnzhw"],["gkxpnpbfvjm","xbogegswmad"],["fpbnsbrkbcyzdmmmoisaa","rbnzendwnoklpyyyauemm"],["aiplrzejplumda","fnuqwejouqzrif"]]]
*/

int main(){
    string arr[] = {
  "fpbnsbrkbcyzdmmmoisaa", "cpjtwqcdwbldwwrryuclcngw", "a", "fnuqwejouqzrif", "js", "qcpr", "zghmdiaqmfelr", "iedda", "l", "dgwlvcyubde", "lpt", "qzq", "zkddvitlk", "xbogegswmad", "mkndeyrh", "llofdjckor", "lebzshcb", "firomjjlidqpsdeqyn", "dclpiqbypjpfafukqmjnjg", "lbpabjpcmkyivbtgdwhzlxa", "wmalmuanxvjtgmerohskwil", "yxgkdlwtkekavapflheieb", "oraxvssurmzybmnzhw", "ohecvkfe", "kknecibjnq", "wuxnoibr", "gkxpnpbfvjm", "lwpphufxw", "sbs", "txb", "ilbqahdzgij", "i", "zvuur", "yfglchzpledkq", "eqdf", "nw", "aiplrzejplumda", "d", "huoybvhibgqibbwwdzhqhslb", "rbnzendwnoklpyyyauemm"  
    };
    vector<string> strings(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<string> > res = groupStrings(strings);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}