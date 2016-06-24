class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        char num[20];
        int size=0;
        while(x){
            int rem = x%10;
            x = x/10;
            num[size++]=rem;
        }
        int start =0; int end = size-1;
        while(start<=end){
            if(num[start++] != num[end--])
                return false;
        }
        return true;
    }
};