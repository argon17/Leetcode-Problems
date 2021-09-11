// O(NlogN) cool solution

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int n : nums){
            // find lower bound of current element
            auto it = lower_bound(ans.begin(), ans.end(), n);
            // if this can be included in LIS
            if(it == ans.end()) ans.push_back(n);
            // else update the lower bound, as it's less
            else *it = n;
        }
        return ans.size();
    }
};