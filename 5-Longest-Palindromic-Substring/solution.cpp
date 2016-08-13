class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size == 1) return s;
        string res;

        //odd pal
        for(int i=0; i<size;i++){
            int start = i-1; int end = i+1;
            while(start>=0 && end<size && s[start]==s[end]){
                if(res.size() < (end-start+1))
                    res = s.substr(start, end-start+1);
                start--;
                end++;
            }
        }

        //even pal
        for(int i=0; i<size;i++){
            int start = i-1; int end = i;
            while(start>=0 && end<size && s[start]==s[end]){
                if(res.size() < (end-start+1))
                    res = s.substr(start, end-start+1);
                start--;
                end++;
            }
        }
   
        return res;
    }
};