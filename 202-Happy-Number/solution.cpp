class Solution {
public:
    bool isHappy(int n) {
        
        if(n<=0)return false;
        int num = n;
        unordered_map<int, int> hash_table;
        
        while(1){
            int sum =  0;
            while(num>0){
                int d = num % 10;
                sum  += (d*d);
                num /= 10;
            }
            if(sum == 1) return true;
            if(hash_table[sum]){
                return false;
            }else{
                hash_table[sum] = 1;
            }
            num = sum;
        }
    }
};