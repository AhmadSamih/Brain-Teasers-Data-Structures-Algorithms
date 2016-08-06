class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cache[512] = {0};
        int m = 0;
        int left = 0;
        for(int i=0; i<s.size(); i++){
            int c = s[i];
            if(cache[c]>0){
                cache[c]++;
                while(left<i){
                    cache[s[left]]--;
                    if(cache[s[left++]] > 0)
                        break;
                }
            }else{
                cache[c] = 1;
                m = max (m, i-left+1);
            }
        }
        return m;
    }
};