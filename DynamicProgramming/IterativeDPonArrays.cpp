// Longest Turbulent Subarray

class Solution {
public:
	int maxTurbulenceSize(vector<int>& a) {
		int n = a.size();
        vector<vector<int>> dp(n, vector<int> (2, 1));
        dp[n-1][0] = 1;
        dp[n-1][1] = 1;
        int ans = 1;
        for(int i = n-2; i >= 0; --i){
            if(a[i] < a[i+1])
                dp[i][0] = 1 + dp[i+1][1];
            if(a[i] > a[i+1])
                dp[i][1] = 1 + dp[i+1][0];
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
	}
};
