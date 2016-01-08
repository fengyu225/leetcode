/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]


There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
*/

#include "header.h"

/* dfs
bool search(int curr, unordered_map<int,vector<int> >& graph, unordered_map<int,int>& m){
    for(int i:graph[curr]){
        if(m[i] == 1) return false;
        if(m[2] == 2) continue;
        m[i] = 1;
        bool res = search(i, graph, m);
        if(!res) return false;
        m[i] = 2;
    }
    return true;    
}

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    unordered_map<int,int> m;
    unordered_map<int,vector<int> > graph;
    for(auto p:prerequisites) graph[p.first].push_back(p.second);
    for(int i=0; i<numCourses; i++){
        if(m[i] == 0){
            m[i] = 1;
            bool res = search(i, graph, m);
            m[i] = 2;
            if(!res) return false;
        }
    }
    return true;
}
*/

/* bfs */
bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    unordered_map<int,int> m; 
}

int main(){
    vector<pair<int,int> > prerequisites = {
        {1, 0},
        {0, 1}
    };
    cout<<canFinish(2, prerequisites)<<endl;
    return 0;
}