class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> g[n];
        for(auto conn : connections){
            g[conn[0]].push_back(conn[1]);
            g[conn[1]].push_back(conn[0]);
        }
        vector<bool> vis(n, false);
        vector<int> tin(n, -1), low(n, -1);
        int timer = 0;
        vector<vector<int>> ans;
        dfs(0, -1, g, vis, timer, tin, low, ans);
        return ans;
    }
private:
    void dfs(int u, int p, vector<int> g[], vector<bool> &vis, int &timer, vector<int> &tin, vector<int> &low, vector<vector<int>> &ans){
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        for(int v : g[u]){
            if(v == p) continue;
            if (vis[v])
                low[u] = min(low[u], tin[v]);
            else {
                dfs(v, u, g, vis, timer, tin, low, ans);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u])
                    ans.push_back({u, v});
            }
        }
    }
};