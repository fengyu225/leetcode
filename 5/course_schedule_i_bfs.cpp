/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include "header.h"


bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites){
    if(numCourses == 0) return true;
    vector<unordered_set<int> > graph(numCourses,unordered_set<int>());
    vector<int> degrees(numCourses, 0);
    for(auto i=prerequisites.begin(); i!=prerequisites.end(); i++) 
        graph[i->second].insert(i->first);
    for(int i=0; i<graph.size(); i++){
        for(auto j = graph[i].begin(); j!=graph[i].end(); j++)
            degrees[*j]++;
    }
    for(int i=0; i<numCourses; i++){
        int j = 0;
        for(;j<numCourses;j++)
            if(degrees[j] == 0) break;
        if(j == numCourses) return false;
        degrees[j] = -1;
        for(auto x = graph[j].begin(); x!=graph[j].end(); x++)
            degrees[*x]--;
    }
    return true;
}

int main(){
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(0, 1));
    cout<<canFinish(2, prerequisites)<<endl;
    return 0;
}