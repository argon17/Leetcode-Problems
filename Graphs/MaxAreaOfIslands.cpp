class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j])
                    ans = max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }

private:
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        grid[i][j] = 0;
        int dirs[] = {0, 1, 0, -1, 0};
        int ans = 0;
        for (int d = 0; d < 4; ++d)
        {
            int ni = i + dirs[d], nj = j + dirs[d + 1];
            if (inside(ni, nj, n, m) && grid[ni][nj])
            {
                ans += dfs(ni, nj, grid);
            }
        }
        return ++ans;
    }
    bool inside(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};