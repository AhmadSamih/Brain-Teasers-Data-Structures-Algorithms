class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int lenh = haystack.length();
        int lenn = needle.length();
        
        if(lenn == 0) return 0;
        
        int j = 0;
        for(int i = 0; i<lenh;i++){
            if(haystack[i] == needle[j]){
                while(j<lenn && (i+j)<lenh){
                    if(haystack[i+j] == needle[j]){
                        j++;
                    }else{
                        j = 0;
                        break;
                    }
                }
                if(j == lenn){
                    return i;
                }
            }
        }
        
        return -1;
    }
};