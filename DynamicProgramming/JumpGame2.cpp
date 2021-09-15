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