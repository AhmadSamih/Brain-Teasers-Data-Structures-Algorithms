class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size == 1) return s;
        int final_start = 0;
        int final_end = 0;

        //odd pal
        for(int i=0; i<size;i++){
            int start = i-1; int end = i+1;
            while(start>=0 && end<size && s[start]==s[end]){
                if(final_end-final_start+1 < end-start+1)
                    final_start = start, final_end = end;
                start--;
                end++;
            }
        }

        //even pal
        for(int i=0; i<size;i++){
            int start = i-1; int end = i;
            while(start>=0 && end<size && s[start]==s[end]){
                if(final_end-final_start+1 < end-start+1)
                    final_start = start, final_end = end;
                start--;
                end++;
            }
        }
   
        return s.substr(final_start, final_end-final_start+1);
    }
};