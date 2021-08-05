#include <bits/stdc++.h>
using namespace std;

void insertEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void removeEdge(vector<int> adj[], int u, int v)
{
    adj[u].erase(std::remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
    adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
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

vector<int> bfs(vector<int> adj[], int n)
{
    vector<int> ans;
    vector<int> visited(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int currNode = q.front();
                q.pop();
                ans.push_back(currNode);
                for (auto j : adj[currNode])
                {
                    if (visited[j] == 0)
                    {
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        insertEdge(adj, u, v);
    }

    int search = 5;
    vector<int> ans = bfs(adj, n);
    for (auto i : ans)
    {
        // cout << i << " ";
    }
    cout << endl;
}