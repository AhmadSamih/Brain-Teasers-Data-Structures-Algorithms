class Solution {
public:
    bool isPalindrome(int x) {
        
        string s= "";
        while(x){
            int rem = x%10;
            x = x/10;
            s+=to_string(rem);
        }
        string rev = s;
        reverse(rev.begin(), rev.end());
        return (rev==s);
    }
};