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

bool visit(int curr, unordered_map<int, vector<int> >& graph, vector<int>& visited){
    visited[curr] = 1;
    for(auto r:graph[curr]){
        if(visited[r] == 1) return false;
        if(visited[r] == 2) continue;
        if(!visit(r, graph, visited)) return false;
    }
    visited[curr] = 2;
    return true;
}

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    if(numCourses == 0) return true;
    unordered_map<int,vector<int> > graph;
    for(auto p:prerequisites){
        if(graph.find(p.first) == graph.end()) graph[p.first] = vector<int>();
        graph[p.first].push_back(p.second);
    }
    vector<int> visited(numCourses, 0);
    for(int i=0; i<numCourses; i++){
        if(visited[i] == 0){
            if(!visit(i, graph, visited)) return false;
        }
    }
    return true;
}

int main(){
    vector<pair<int, int> > prerequisites;
//    prerequisites.push_back(make_pair(1, 0));
//    prerequisites.push_back(make_pair(0, 1));
    cout<<canFinish(2, prerequisites)<<endl;
    return 0;
}