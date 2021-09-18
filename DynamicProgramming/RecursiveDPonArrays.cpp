// House Robber

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

// Iterative solution also, similar to fibonacci

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

// House Robber 2

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n?nums[0]:0;
        return max(getRob(nums, 0, n-2), getRob(nums, 1, n-1));
    }
private:
    int getRob(vector<int> &a, int lo, int hi){
        int prev = 0, cur = 0;
        for(int i = lo; i <= hi; ++i){
            int prevprev = prev;
            prev = cur;
            cur = max(prevprev + a[i], prev);
        }
        return cur;
    }
};

// Jump Game 2

class Solution {
public:
    int jump(vector<int>& nums) {
        a = nums;
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return tryfrom(0);
    }
private:
    vector<int> a;
    int dp[10005];
    int n;
    int tryfrom(int at){
        int ans = 1e9;
        if(at >= n) return ans;
        if(at == n - 1) return 0;
        if(dp[at] != -1) return dp[at];
        for(int step = 1; step <= a[at]; ++step){
            if(at + step >= n) break;
            ans = min(ans, 1 + tryfrom(at + step));
        }
        return dp[at] = ans;
    }
};