class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        // dp[i] = palindrome size of mask i
        vector<int> dp;
        int all = (1 << n);
        dp.resize(all);
        int ans = 0;
        for (int mask = 1; mask < all; ++mask)
            dp[mask] = palSize(s, mask);
        for (int mask1 = 1; mask1 < all; ++mask1)
            for (int mask2 = mask1 + 1; mask2 < all; ++mask2)
                if ((mask1 & mask2) == 0)
                    ans = max(dp[mask1] * dp[mask2], ans);
        return ans;
    }


private:
    int palSize(string s, int mask) {
        int i = 0, j = s.size() - 1, ans = 0;
        while (i <= j) {
            if ((mask & (1 << i)) == 0) ++i;
            else if ((mask & (1 << j)) == 0) --j;
            else if (s[i] != s[j]) return 0;
            else ans += 1 + (i++ != j--);
        }
        cerr << bitset<3>(mask) << " " << ans << endl;
        return ans;
    }

};