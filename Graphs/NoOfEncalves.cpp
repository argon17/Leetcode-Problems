class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            if (grid[0][i])
                dfs(i, grid);
            if (grid[n - 1][i])
                dfs((n - 1) * m + i, grid);
        }
        for (int i = 0; i < n; ++i)
        {
            if (grid[i][0])
                dfs(i * m, grid);
            if (grid[i][m - 1])
                dfs(i * m + m - 1, grid);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += grid[i][j];
        return ans;
    }

private:
    void dfs(int cur, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int dirs[] = {0, 1, 0, -1, 0};
        int i = cur / m, j = cur % m;
        grid[i][j] = 0;
        for (int d = 0; d < 4; ++d)
        {
            int ni = i + dirs[d], nj = j + dirs[d + 1];
            if (inside(ni, nj, n, m) && grid[ni][nj])
                dfs(ni * m + nj, grid);
        }
    }
    bool inside(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};
