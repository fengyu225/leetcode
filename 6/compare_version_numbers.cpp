/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
*/

#include "header.h"

int compareVersion(string version1, string version2) {

}

int main(){
    cout<<compareVersion("10.6.5","10.6")<<endl;
    cout<<compareVersion("0","1")<<endl;
    cout<<compareVersion("0.1","1.1")<<endl;
    cout<<compareVersion("1.1","1.2")<<endl;
    cout<<compareVersion("1.2","13.7")<<endl;
    return 0;
}