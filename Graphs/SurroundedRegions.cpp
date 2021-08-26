class Solution
{
public:
    void solve(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int dirs[] = {0, 1, 0, -1, 0};
        auto inside = [&](int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        queue<int> q;
        for (int j = 0; j < m; ++j)
        {
            if (grid[0][j] == 'O') q.push(j);
            if (grid[n - 1][j] == 'O') q.push((n - 1) * m + j);
        }
        for (int i = 0; i < n; ++i)
        {
            if (grid[i][0] == 'O') q.push(i * m);
            if (grid[i][m - 1] == 'O') q.push(i * m + m - 1);
        }
        while (q.size())
        {
            int cur = q.front();
            q.pop();
            int i = cur / m, j = cur % m;
            grid[i][j] = 'A';
            for (int d = 0; d < 4; ++d)
            {
                int ni = i + dirs[d], nj = j + dirs[d + 1];
                if (inside(ni, nj) && grid[ni][nj] == 'O')
                    q.push(ni * m + nj);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                if (grid[i][j] == 'A') grid[i][j] = 'O';
            }
        }
    }
};
