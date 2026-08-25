class Solution {
public:
    vector<int> visited;

    void dfs(int node, vector<vector<int>>& graph) {
        visited[node] = 1;

        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, graph);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree with n nodes must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        // Build adjacency list
        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        visited.resize(n, 0);

        // Start DFS from node 0
        dfs(0, graph);

        // Check if every node was visited
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0)
                return false;
        }

        return true;
    }
};