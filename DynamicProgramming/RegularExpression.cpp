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