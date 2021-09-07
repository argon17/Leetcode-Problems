class Solution {
public:
    vector<string> generateParenthesis(int n) {
        go("", n, n);
        return ans;
    }
private:
    vector<string> ans;
    void go(string cur, int l, int r){
        if(l == 0 && r == 0){
            ans.push_back(cur);
            return;
        }
        if(l > 0) go(cur + "(", l - 1, r);
        if(r > l) go(cur + ")", l, r - 1);
    }
};