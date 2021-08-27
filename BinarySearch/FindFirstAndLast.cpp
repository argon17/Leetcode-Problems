// very cool implementation
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size(), lo = 0, mid, hi = n;
        int left, right;
        while (lo < hi)
        {
            mid = (lo + hi) >> 1;
            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        left = lo;
        lo = left, hi = n;
        while (lo < hi)
        {
            mid = (lo + hi) >> 1;
            if (nums[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        right = lo;
        return left == right ? vector<int>{-1, -1} : vector<int>{left, right - 1};
    }
};