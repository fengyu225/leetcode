/*
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3

return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5

return [3, 4]

Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

#include "header.h"

vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
    if(edges.size() == 0) return vector<int>(1, 0);
    vector<int> res;
    vector<unordered_set<int> > graph(n);
    vector<int> degree(n, 0);
    for(pair<int,int> e:edges){
        graph[e.first].insert(e.second);
        graph[e.second].insert(e.first);
    }
    queue<int> qs[2];
    int curr = 0;
    for(int i=0; i<n; i++){
        degree[i] = graph[i].size();
        if(degree[i] == 1) qs[curr].push(i);
    }
    for(int remains = n; remains>2;){
        while(!qs[curr%2].empty()){
            int temp = qs[curr%2].front();
            qs[curr%2].pop();
            remains--;
            for(int i:graph[temp]){
                degree[i]--;
                graph[i].erase(temp);
                if(degree[i] == 1) qs[(curr+1)%2].push(i);
            }
        }
        curr++;
    }
    while(!qs[curr%2].empty()){
        res.push_back(qs[curr%2].front());
        qs[curr%2].pop();
    }
    return res;
}

int main(){
    vector<pair<int,int> > edges = {
        {0, 3},
        {1, 3},
        {2, 3},
        {4, 3},
        {5, 4}
    };     
    vector<int> res = findMinHeightTrees(6, edges);
//    vector<pair<int,int> > edges = {
//        {1, 0},
//        {1, 2},
//        {1, 3}
//    vector<int> res = findMinHeightTrees(4, edges);
    print_vector<int>(res);
    return 0;
}