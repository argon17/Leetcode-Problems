class Solution {
public:
    bool exist(vector<vector<char>>& b, string word) {
        n = b.size(), m = b[0].size();
        // vis.resize(n*m, 0);
        g = b;
        t = word;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(letsgo(0, i*m + j)) return 1;
            }
        }
        return 0;
    }
private:
    int n, m;
    string t;
    // vector<bool> vis;
    vector<vector<char>> g;
    bool letsgo(int ind, int cur){
        int i = cur/m, j = cur%m;
        if(t[ind] != g[i][j]) return 0;
        if(ind+1 == t.size()) return 1;
        g[i][j] = '\0';
        // vis[cur] = 1;
        int dirs[5] = {0,1,0,-1,0};
        for(int d = 0; d < 4; ++d){
            int ni = i + dirs[d], nj = j + dirs[d+1];
            if(inside(ni, n, nj, m) && g[ni][nj]!='\0'/* && !vis[ni*m + nj]*/){
                if(letsgo(ind+1, ni*m + nj)) return 1;
                // vis[ni*m+nj] = 0;
            }
        }
        g[i][j] = t[ind];
        // vis[cur] = 0;
        return 0;
    }
    bool inside(int i, int r, int j = 0,  int c = 1) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
};