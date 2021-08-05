#include <bits/stdc++.h>

using namespace std;
void removeEdge(vector<int> adj[], int u, int v)
{
    adj[u].erase(std::remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
    adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAdj(vector<int> adj[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE

    // // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);

    // // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);

    // #endif

    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;

    //1 based graph indexing
    vector<int> adj[n + 1];
    // vector<pair<int, int>> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        // an edge exists between u anv v
        int u, v;
        cin >> u >> v;
        // int wt; cin >> wt;

        // if non-bidirectional using only one
        adj[u].push_back(v);
        adj[v].push_back(u);

        // adj[u].push_back(make_pair(v, wt));
        // adj[v].push_back(make_pair(v, wt));
    }
}