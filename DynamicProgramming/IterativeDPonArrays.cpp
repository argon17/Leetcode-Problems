/*
    Longest Turbulent Subarray
    Input: arr = [9,4,2,10,7,8,8,1,9]
    Output: 5
    Explanation: 4>2<10>7<8 
*/

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        // dp[i][0] = size of subarray starting at i, with a[i] < a[i+1]
        // dp[i][1] = size of subarray starting at i, with a[i] > a[i+1]
        int ans = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] < a[i + 1])
                dp[i][0] = 1 + dp[i + 1][1];
            if (a[i] > a[i + 1])
                dp[i][1] = 1 + dp[i + 1][0];
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};

/*
===========================================================================================================
*/
/*
    Count Square Submatrices with All Ones
    DP on 2D arrays.
*/

class Solution
{
public:
    int countSquares(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) dp[i][0] = a[i][0];
        for (int j = 0; j < m; ++j) dp[0][j] = a[0][j];
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (a[i][j])
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += dp[i][j];
        return ans;
    }
};