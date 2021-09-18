class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> cnt;
        for(auto it : rectangles){
            cnt[1.0*it[0]/it[1]]++;
        }
        long long ans = 0;
        for(auto it : cnt){
            long long here = it.second;
            cout<<it.second<<" ";
            ans += here*(here-1)/2;
        }
        return ans;
    }
};