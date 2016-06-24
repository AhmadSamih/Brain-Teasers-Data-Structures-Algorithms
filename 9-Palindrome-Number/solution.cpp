class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false; if(x==0)return true;
        
        int size = log10(x)+1;
        char num[size];
        
        int idx =0;
        while(x){
            int rem = x%10;  x = x/10;
            num[idx++]=rem;
        }
        
        int start =0; int end = size-1;
        while(start<=end){
            if(num[start++] != num[end--])
                return false;
        }
        return true;
    }
};