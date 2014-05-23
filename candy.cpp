#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

int candy(vector<int> &ratings){
    if(ratings.size()==1)
        return 1;
    vector<int> num(ratings.size(),1);
    vector<int>::iterator iter,iter_c;
    for(
            iter=ratings.begin()+1,
            iter_c=num.begin()+1; 
            iter<ratings.end(),iter_c<num.end(); iter++,iter_c++
            )
    {
        if(*iter>*(iter-1))
            *iter_c=*(iter_c-1)+1;
    }

    int max = 0;
    for(
            iter=ratings.end()-2,
            iter_c=num.end()-2; 
            iter>=ratings.begin(),iter_c>=num.begin(); iter--,iter_c--
            )
    {
        if(*iter>*(iter+1) && *iter_c<=*(iter_c+1))
            *iter_c=*(iter_c+1)+1;
    }


    for(vector<int>::iterator iter = num.begin(); iter<num.end(); iter++)
        max += *iter;
    return max;
}

int main(){
    //int rating_arr[] = {5, 4, 3, 6, 4, 1, 2};
    int rating_arr[] = {4, 2, 3, 4, 1};
    vector<int> ratings(rating_arr, rating_arr+sizeof(rating_arr)/sizeof(rating_arr[0]));
    printf("%d\n", candy(ratings));
    return 0;
}
