class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>cache;
        int m = 0;
        int left = 0;
        for(int i=0; i<s.size(); i++){
            if(cache.count(s[i]) && cache[s[i]]>0){
                cache[s[i]]++;
                while(left<i){
                    cache[s[left]]--;
                    if(cache[s[left++]] > 0)
                        break;
                }
            }else{
                cache[s[i]] = 1;
                m = max (m, i-left+1);
            }
        }
        return m;
    }
};