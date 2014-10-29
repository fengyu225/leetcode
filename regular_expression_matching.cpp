#include "header.h"

bool isMatch(const char *s, const char *p) {
  assert(s && p);
  if (*p == '\0') return *s == '\0';
 
  // next char is not '*': must match current character
  if (*(p+1) != '*') {
    assert(*p != '*');
    return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
  }
  while((*p == *s) || (*p == '.' && *s != '\0')){
      if(isMatch(s,p+2)) return true;
      s++;
  }
  return isMatch(s,p+2);
}

int main(){
//    printf("%d\n",isMatch("aa","a"));
//    printf("%d\n",isMatch("aa","aa"));
//    printf("%d\n",isMatch("aaa","aa"));
//    printf("%d\n",isMatch("aa", "a*"));
//    printf("%d\n",isMatch("aa", ".*"));
//    printf("%d\n",isMatch("ab", ".*"));
//    printf("%d\n",isMatch("aab", "c*a*b"));
    printf("%d\n",isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c"));
    return 0;
}
