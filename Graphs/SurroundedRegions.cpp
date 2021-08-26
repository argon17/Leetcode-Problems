class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        int dirs[] = {0, 1, 0, -1, 0};
        auto inside = [&](int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        queue<int> q;
        for (int i = 0; i < m; ++i)
        {
            if (board[0][i] == 'O') q.push(i);
            if (board[n - 1][i] == 'O') q.push((n - 1) * m + i);
        }
        for (int i = 0; i < n; ++i)
        {
            if (board[i][0] == 'O') q.push(i * m);
            if (board[i][m - 1] == 'O') q.push(i * m + m - 1);
        }
        while (q.size())
        {
            int cur = q.front();
            q.pop();
            int i = cur / m, j = cur % m;
            board[i][j] = 'A';
            for (int d = 0; d < 4; ++d)
            {
                int ni = i + dirs[d], nj = j + dirs[d + 1];
                if (inside(ni, nj) && board[ni][nj] == 'O')
                    q.push(ni * m + nj);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};
