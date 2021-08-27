// O(n*m) TC & O(n*m) SC, but cool implementation
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int dirs[] = {0, 1, 0, -1, 0};
        auto okay = [&](int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0;
        };
        vector<int> ans;
        // starting at {0, -1}
        int cur = -1;
        // no of cells to visit
        int left = n * m;
        while (left)
        {
            for (int i = 0; i < 4; ++i)
            {
                // if next cell is okay to visit, then visit it
                while (okay(cur / m + dirs[i], cur % m + dirs[i + 1]))
                {
                    cur = (cur / m + dirs[i]) * m + cur % m + dirs[i + 1];
                    vis[cur / m][cur % m] = 1;
                    ans.push_back(matrix[cur / m][cur % m]);
                    --left;
                }
            }
        }
        return ans;
    }
};