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