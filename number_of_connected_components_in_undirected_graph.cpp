/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

     0          3
     |          |
     1 --- 2    4

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:

     0           4
     |           |
     1 --- 2 --- 3

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

*/

#include "header.h"

//void search(unordered_map<int,vector<int> >& edges, int i, vector<bool>& visited){
//    for(int j:edges[i]){
//        if(!visited[j]){
//            visited[j] = true;
//            search(edges, j, visited);
//        }
//    } 
//}
//
//int countComponents(int n, vector<pair<int, int> >& edges) {
//    //DFS
//    int res = 0;
//    vector<bool> visited(n, false);
//    unordered_map<int,vector<int> > edges_map;
//    for(auto e:edges){
//        edges_map[e.first].push_back(e.second);
//        edges_map[e.second].push_back(e.first);
//    }
//    for(int i=0; i<n; i++){
//        if(!visited[i]){
//            res++;
//            visited[i] = true;
//            search(edges_map, i, visited);
//        }
//    }
//    return res;
//}

//void search(unordered_map<int,vector<int> >& edges, int i, vector<bool>& visited){
//    queue<int> q;
//    q.push(i);
//    while(!q.empty()){
//        int temp = q.front();
//        q.pop();
//        for(int j:edges[temp]){
//            if(!visited[j]){
//                visited[j] = true;
//                q.push(j);
//            }
//        }
//    }
//}
//
//int countComponents(int n, vector<pair<int, int> >& edges) {
//    //BFS
//    int res = 0;
//    unordered_map<int,vector<int> > edges_map;
//    for(auto e:edges){
//        edges_map[e.first].push_back(e.second);
//        edges_map[e.second].push_back(e.first);
//    }
//    vector<bool> visited(n, false);
//    for(int i=0; i<n; i++){
//        if(!visited[i]){
//            res++;
//            visited[i] = true;
//            search(edges_map, i, visited);
//        }
//    }
//    return res;
//}

class Node{
    public:
        int x, rank;
        Node* parent;
        Node(int x):x(x),rank(1),parent(this){}
};

Node* f(Node* n){
    if(n == n->parent) return n;
    n->parent = f(n->parent);
    return n->parent;
}

Node* u(Node* m, Node* n, int& res){
    Node* p_m = f(m);
    Node* p_n = f(n);
    if(p_m == p_n) return p_m;
    if(p_m->rank<p_n->rank){
        p_m->parent = p_n;
        res--;
        return p_n;
    }
    else{
        p_n->parent = p_m;
        if(p_m->rank == p_n->rank) p_m->rank++;
        res--;
        return p_m;
    }
}

int countComponents(int n, vector<pair<int, int> >& edges) {
    int res = n;
    vector<Node*> nodes(n); 
    for(int i=0; i<n; i++) nodes[i] = new Node(i);
    for(auto e:edges){
        u(nodes[e.first], nodes[e.second], res); 
    }
    return res;
}

int main(){
    vector<pair<int,int> > edges = {
        {0, 1},
        {1, 2},
        {3, 4}
    };
    cout<<countComponents(5, edges)<<endl;
    return 0;
}