class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while(l < r){
            int h = min(height[l], height[r]);
            ans = max(ans, (r - l) * h);
            // this was the best left could do
            // now we don't need l, bye bye l
            if(height[l] <= height[r]) ++l;
            else --r;
        }
        return ans;
    }
};