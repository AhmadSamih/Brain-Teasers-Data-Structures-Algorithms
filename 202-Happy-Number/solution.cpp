class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int>cache;
        
        int sum = 0;
        for(;;){
            sum = 0;
            while(n){
                int div = n%10;
                n = n/10;
                sum+= div*div;
            }
            n = sum;
            if(sum == 1) return true;
            if(cache.find(sum)!=cache.end())return false;
            cache[sum] = 1;
        }
    }
};