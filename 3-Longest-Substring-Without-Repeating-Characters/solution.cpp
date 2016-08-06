class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>cache(256,-1);
        int m = 0;
        int left = 0;

        for(int i=0; i<s.size(); i++){
            left = max(left, cache[s[i]]+1);
            m = max(m, i-left+1);
            cache[s[i]] = i;
        }
        return m;
    }
};