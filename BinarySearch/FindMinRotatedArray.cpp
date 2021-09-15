// if consisting of Unique elements

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(nums[mid] < nums[hi]) hi = mid;
            else lo = mid + 1;
        }
        return nums[lo];
    }
};

// if consisting of Duplicates elements

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            // only eliminate the elements, you're sure of
            if(nums[mid] < nums[hi]) hi = mid;
            else if(nums[mid] > nums[hi]) lo = mid + 1;
            else --hi;
        }
        return nums[lo];
    }
};