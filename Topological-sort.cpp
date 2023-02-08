#include <bits/stdc++.h> 
using namespace std;

void dfsTraversal(int src, vector<int>adj[], vector<int> &vis, stack<int> &topoStk){
    
    vis[src] = 1;

    for(auto it: adj[src]){
        if(!vis[it]){
            dfsTraversal(it, adj, vis, topoStk);
        }
    }
    topoStk.push(src);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    vector<int>adj[v];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int>topoArr;
    stack<int>topoStk;
    vector<int>vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfsTraversal(i,adj,vis,topoStk);
        }
    }
    while(!topoStk.empty()){
        int temp = topoStk.top();
        topoStk.pop();
        topoArr.push_back(temp);
    }
    return topoArr;
}