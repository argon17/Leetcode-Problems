class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int p = 1;
        int ans = 0;
        while (r < nums.size())
        {
            p *= nums[r];
            while (l <= r && p >= k)
                p /= nums[l++];
            ans += r++ - l + 1;
        }
        return ans;
    }
};