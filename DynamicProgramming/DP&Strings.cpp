class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = s[i - 1] == t[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

class Solution
{
public:
    int minDistance(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

class Solution
{
public:
    int minDistance(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (i == 0 || j == 0) dp[i][j] = i + j;
                else dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
        return dp[n][m];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it : wordDict)
            exists[it] = 1;
        t = s;
        n = s.size();
        memset(dp, -1, sizeof dp);
        return krpaoge(n);
    }
private:
    unordered_map<string, bool> exists;
    int n;
    string t;
    int dp[500];
    // p length match kr paoge?
    bool krpaoge(int p){
        if(dp[p] != -1) return dp[p];
        if(p == 0) return 1; // kr liye bro
        for(int i = p-1; i >= 0; --i)
            if(exists[t.substr(i, p-i)] && krpaoge(i)) return dp[p] = 1;
        return dp[p] = 0;
    }
};

// Regular Expression

// i don't know why greedy way of skipping all *s works here

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        ss = s, pp = p;
        n = s.size(), m = p.size();
        memset(dp, -1, sizeof dp);
        return aagekrlo(0, 0);
    }

private:
    int n, m;
    int dp[50][50];
    string ss, pp;
    bool aagekrlo(int i, int j)
    {
        // we'll be sure of all mathced only when our pattern length ends
        if (j == m) return i == n;
        if (dp[i][j] != -1) return dp[i][j];
        // always try to skip all *s first
        if (pp[j + 1] == '*')
        {
            // always try to skip all *s first
            if (aagekrlo(i, j + 2)) return 1;
            // if matching try to find more matches
            if (ss[i] == pp[j] || pp[j] == '.')
                return dp[i][j] = i < n && aagekrlo(i + 1, j);
        }
        // if current character matches
        if (ss[i] == pp[j] || pp[j] == '.')
            return dp[i][j] = i < n && aagekrlo(i + 1, j + 1);
        // if none of the above cases are valid
        return dp[i][j] = 0;
    }
};