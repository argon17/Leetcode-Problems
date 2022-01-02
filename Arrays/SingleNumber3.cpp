class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xr = 0;
        for(int num : nums) xr ^= num;
        long lastSetBit = xr & ~(xr - 1);
        int g1 = 0, g2 = 0;
        for(int num : nums){
            if(lastSetBit & num) g1 ^= num;
            else g2 ^= num;
        }
        return {g1, g2};
    }
};