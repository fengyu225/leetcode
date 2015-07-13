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

bool visit(unordered_map<int, vector<int> >& graph, unordered_map<int,int>& m, int curr){
    m[curr] = 1;
    vector<int> n = graph[curr];
    for(int i=0; i<n.size(); i++){
        if(m[n[i]] == 1) return false;
        m[n[i]] = 1;
        bool res = visit(graph, m, n[i]);
        if(!res) return false;
        m[n[i]] = 2;
    }
    m[curr] = 2;
    return true;
} 

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites){
    if(numCourses == 0) return true;
    unordered_map<int, int> m;
    unordered_map<int, vector<int> > graph;
    for(int i=0; i<prerequisites.size(); i++){
        int from = prerequisites[i].first;
        int to = prerequisites[i].second;
        if(graph.find(from) == graph.end()){
            graph[from] = vector<int>();
        }
        graph[from].push_back(to);
    }
    for(int i=1; i<numCourses; i++){
        if(m[i]==0){
            bool res = visit(graph, m, i);
            if(!res) return false;
        }
    }
    return true;
}

int main(){
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1, 0));
//    prerequisites.push_back(make_pair(0, 1));
    cout<<canFinish(2, prerequisites)<<endl;
    return 0;
}