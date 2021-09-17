class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int m = (l + r) >> 1;
            // our answer will definitely not be in [l..m]
            if(nums[m] < nums[m+1]) l = m + 1;
            // our answer will be in [l..m]
            else r = m;
        }
        return l;
    }
};