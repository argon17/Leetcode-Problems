class Solution
{
public:
    int rob(vector<int> &nums)
    {
        dp.resize(nums.size(), -1);
        return max(aagekrlo(0, nums), aagekrlo(1, nums));
    }

private:
    vector<int> dp;
    int aagekrlo(int i, vector<int> &a)
    {
        if (i >= a.size()) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(aagekrlo(i + 1, a), a[i] + aagekrlo(i + 2, a));
    }
};

// Iterative DP

class Solution {
public:
    int rob(vector<int>& nums) {
        // prevprev = till prev of prev house
        // prev = till prev house
        // curr = till curr house
        int prev = 0, cur = 0;
        for(int num : nums){
            int prevprev = prev;
            prev = cur;
            cur = max(prevprev + num, prev);
        }
        return cur;
    }
};