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

bool visit(vector<vector<int> >& graph, vector<int>& m, int curr, vector<int>& res){
    m[curr] = 1;
    for(int i=0; i<graph[curr].size(); i++){
        if(m[graph[curr][i]] == 1) return false;
        if(m[graph[curr][i]] == 2) continue;
        bool x = visit(graph, m, graph[curr][i], res);
        if(!x) return false;
    }
    m[curr] = 2;
    res.push_back(curr);
    return true;
}

vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites){
    vector<int> res;
    vector<int> m(numCourses,0);
    vector<vector<int> > graph(numCourses,vector<int>());
    for(auto i = prerequisites.begin(); i!=prerequisites.end(); i++){
        graph[i->second].push_back(i->first);
    }
    for(int i=0; i<numCourses; i++){
        if(m[i] == 0){
            bool x = visit(graph,m,i,res);
            if(!x) return vector<int>();
        }
    }
    reverse(res.begin(), res.end());
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