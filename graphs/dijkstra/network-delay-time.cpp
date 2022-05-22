// https://leetcode.com/problems/network-delay-time/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void addEdge(vector<pair<int,int>> adj[], int u, int v, int k)
    {
        adj[u].push_back(make_pair(v, k));
    }
    
    void printGraph(vector<pair<int,int>> adj[], int n)
    {
        for(int i=0;i<n+1;i++)
        {
            cout<<i<<"-> ";
            for(auto j: adj[i])
            {
                cout<<j.first<<", "<<j.second<<" | ";
            }
            cout<<"\n";
        }
    }
    
    void helper(vector<pair<int,int>> adj[], int source, int curr, int n, vector<int> &visited, vector<int> &dist)
    {
        //mark curr as visited
        visited[curr] = 1;
        
        //update dist with vertices reachable from curr node
        for(auto i: adj[curr])
        {
            // i = <node, dist>
            int node = i.first;
            int distFromCurrToNode = i.second;
            
            int distFromSourceThroughCurrToNode = dist[curr] + distFromCurrToNode;
            if(distFromSourceThroughCurrToNode < dist[node])
            {
                dist[node] = distFromSourceThroughCurrToNode;
            }
        }
        
        int newCurr = getMin(dist, visited);
        
        //basecase
        if(newCurr == 0)
            return;
        
        helper(adj, source, newCurr, n, visited, dist);
        
        
    }
    
    vector<int> dijkstra(vector<pair<int,int>> adj[], int start, int n)
    {
        vector<int> visited(n+1, 0);
        vector<int> dist(n+1, INT_MAX);
        dist[start] = 0;
        
        //source is marked visited
        visited[start] = 1;
        
        //update dist with vertices reachable from curr node
        for(auto i: adj[start])
        {
            // i = <node, dist>
            int node = i.first;
            int localDist = i.second;
            dist[node] = localDist;
        }
        
        int minNode = getMin(dist, visited);
        
        helper(adj, start, minNode, n, visited, dist);
        
        return dist;
    }
    
    //get node with least distance from source which is not in visited
    int getMin(vector<int> &dist, vector<int> &visited)
    {
        int node = 0;
        int minDist = INT_MAX;
        for(int i = 1;i<dist.size();i++)
        {
            if(visited[i] == 0 && dist[i] < minDist)
            {
                node = i;
                minDist = dist[i];
            }
        }
        return node;
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)     {
        // <v,weight>[u]
        vector<pair<int,int>> adj[n+1];
        for(auto i: times)
        {
            addEdge(adj, i[0], i[1], i[2]);
        }
        
        printGraph(adj, n);
        
        vector<int> dist = dijkstra(adj, k, n);
        
        int ans = *max_element(dist.begin() + 1, dist.end());
        if(ans == INT_MAX)
            return -1;
        else return ans;
        
    }
};