class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        vector<int> ans, goal(26), cur(26);
        if (k > n) return ans;
        for (char c : p) goal[c - 'a']++;
        for (int i = 0; i < n; ++i) {
            ++cur[s[i] - 'a'];
            if (i >= k) --cur[s[i - k] - 'a'];
            if (cur == goal) ans.push_back(i - k + 1);
        }
        return ans;
    }
};

class Solution {
public:
    bool checkInclusion(string p, string s) {
        int n = s.size(), k = p.size();
        vector<int> cur(26), goal(26);
        if(k > n) return 0;
        for (char c : p) goal[c - 'a']++;
        for (int i = 0; i < n; ++i) {
            cur[s[i] - 'a']++;
            if (i >= k) cur[s[i - k] - 'a']--;
            if (cur == goal) return 1;
        }
        return 0;
    }
};