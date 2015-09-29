/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]

There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
*/

#include "header.h"

bool visit(int curr, unordered_map<int, vector<int> >& graph, vector<int>& visited, vector<int>& res){
    visited[curr] = 1;
    for(int n:graph[curr]){
        if(visited[n] == 1) return false;
        if(visited[n] == 2) continue;
        if(!visit(n, graph, visited, res)) return false;
    }
    visited[curr] = 2;
    res.push_back(curr);
    return true;
}

vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<int> res;
    if(numCourses == 0) return res;
    vector<int> visited(numCourses, 0);
    unordered_map<int, vector<int> > graph;
    for(pair<int,int> p:prerequisites){
        if(graph.find(p.first) == graph.end()) graph[p.first] = vector<int>();
        graph[p.first].push_back(p.second);
    }
    for(int i=0; i<numCourses; i++){
        if(visited[i] == 0){
            if(!visit(i, graph, visited, res)) return vector<int>();
        }
    }
    return res;
}   

int main(){
    vector<pair<int,int> > prerequisites;
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(2,0));
    prerequisites.push_back(make_pair(3,1));
    prerequisites.push_back(make_pair(3,2));
    vector<int> res = findOrder(4,prerequisites);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}