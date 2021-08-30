class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums, target);
        int right = lower_bound(nums, target + 1) - 1;
        if(left <= right) return {left, right};
        return {-1, -1};
    }
private:
    int lower_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};