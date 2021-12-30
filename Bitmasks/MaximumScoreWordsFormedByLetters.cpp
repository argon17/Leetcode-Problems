class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26);
        for(char letter : letters) count[letter - 'a']++;
        int ans = 0;
        for(int mask = 0; mask < (1 << words.size()); ++mask)
            ans = max(ans, tryy(mask, words, count, score));
        return ans;
    }
private:
    int tryy(int mask, vector<string> &words, vector<int> count, vector<int> &score){
        int ans = 0;
        for(int i = 0; i < words.size(); ++i)
            if(mask & (1 << i))
                for(char c : words[i]){
                    ans += score[c - 'a'];
                    if(--count[c - 'a'] < 0) return -1;
                }
        return ans;
    }
};