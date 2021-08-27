class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e5));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push(i * m + j);
                    vis[i][j] = 1;
                }
            }
        }
        int dirs[] = {0, 1, 0, -1, 0};
        while (q.size())
        {
            int sz = q.size();
            while (sz--)
            {
                int cur = q.front();
                q.pop();
                int i = cur / m, j = cur % m;
                for (int d = 0; d < 4; ++d)
                {
                    int ni = i + dirs[d], nj = j + dirs[d + 1];
                    if (inside(ni, nj, n, m) && !vis[ni][nj])
                    {
                        dist[ni][nj] = 1 + dist[i][j];
                        q.push(ni * m + nj);
                        vis[ni][nj] = 1;
                    }
                }
            }
        }
        return dist;
    }

private:
    bool inside(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};