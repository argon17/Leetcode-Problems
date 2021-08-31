class Solution
{
public:
    bool checkInclusion(string p, string s)
    {
        int n = s.size(), k = p.size();
        vector<int> cur(26), goal(26);
        for (char c : p) goal[c - 'a']++;
        for (int i = 0; i < n; ++i)
        {
            cur[s[i] - 'a']++;
            if (i >= k)
                cur[s[i - k] - 'a']--;
            if (cur == goal)
                return 1;
        }
        return 0;
    }
};