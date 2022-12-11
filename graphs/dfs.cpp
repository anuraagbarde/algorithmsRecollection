class Graph{
public:
    unordered_map<int, vector<int>> g; // use unordered_map<int, unordered_set<int>> if multiple edges are to be ignored 

    Graph()
    {
        unordered_map<int, vector<int>> graph;
        g = graph;
    }

    void add_edge_directional(int u, int v)// u -> v
    {
        if(g.find(u) == g.end())
        {
            vector<int> a = {v};
            g[u] = a;
        }else
        {
            g[u].push_back(v);
        }
    }

    void add_edge(int u, int v){
        add_edge_directional(u, v);
        add_edge_directional(v, u);
    }

    void print_dfs_helper(int &i, vector<int> &visited)
    {
        visited[i] = 1;
        cout<<i<<" ";
        vector<int> &frontierNodes = g[i];
        for(int &j: frontierNodes)
        {
            if(visited[j] == 1){
                return;
            }else{
                print_dfs_helper(j, visited);
            }
        }
    }

    void print_dfs()
    {
        int n = g.size();
        vector<int> visited(n+1);

        int i = 1;
        print_dfs_helper(i, visited);
    }
};

int main(){
        Graph g;
        //nodes are from 1 to n, edges are like [[1,2], [2,3], [1, 3]]        
        vector<vector<int>> edges = {{1,2}, {2, 3}, {1,3}};
        for(vector<int> &i: edges)
        {
            g.add_edge(i[0], i[1]);
        }
    
        g.print_dfs();

        return {1};
    }
};
