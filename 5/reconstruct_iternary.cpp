/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/

#include "header.h"

/*
Keep going one path until stuck, then retreat and push the vertices along the route to a stack until it reaches a vertex that has alternative paths, then go along that path and repeat the process. The assumption for this to work is there is guaranteed to exist one Euler path. (This problem is basically to find a Euler path of a graph).
*/

void search(string curr, vector<string>& res, unordered_map<string,queue<string> >& graph){
    auto & edges = graph[curr];
    while(!edges.empty()){
        string to = edges.front();
        edges.pop();
        search(to, res, graph);
    }
    res.push_back(curr);
}

vector<string> findItinerary(vector<pair<string, string> > tickets) {
    vector<string> res;
    sort(tickets.begin(), tickets.end());
    unordered_map<string,queue<string> > graph;
    for(auto p : tickets) graph[p.first].push(p.second);
    search("JFK", res, graph);
    reverse(res.begin(), res.end());
    return res;
}

int main(){
//    vector<pair<string,string> > tickets = {
//        {"MUC", "LHR"},
//        {"JFK", "MUC"},
//        {"SFO", "SJC"},
//        {"LHR", "SFO"}
//    };
//    vector<pair<string,string> > tickets = {
//        {"JFK","SFO"},
//        {"JFK","ATL"},
//        {"SFO","ATL"},
//        {"ATL","JFK"},
//        {"ATL","SFO"}
//    };
    vector<pair<string,string> > tickets = {
        {"JFK","KUL"},
        {"JFK","NRT"},
        {"NRT","JFK"}
    };
    vector<string> res = findItinerary(tickets);
    print_vector<string>(res);
    return 0;
}
