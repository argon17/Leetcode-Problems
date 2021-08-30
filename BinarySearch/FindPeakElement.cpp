class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(mid == n-1 || nums[mid] < nums[mid+1]) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};