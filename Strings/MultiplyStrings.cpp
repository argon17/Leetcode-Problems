class Solution
{
public:
    string multiply(string a, string b)
    {
        if (a == "0" || b == "0") return "0";
        int n = a.size(), m = b.size();
        vector<int> ans(n + m);
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                ans[i + j + 1] += (a[i] - '0') * (b[j] - '0');
                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] %= 10;
            }
        }
        string res;
        int i = 0;
        while (i < n + m && ans[i] == 0) ++i;
        while (i < n + m)
            res.push_back(ans[i++] + '0');
        return res;
    }
};