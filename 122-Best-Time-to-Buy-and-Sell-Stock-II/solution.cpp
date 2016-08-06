class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int>R(size,0);
        for(int i=size-2; i>=0;i--){
            R[i] = max(prices[i+1], R[i+1]);
            if(prices[i] > prices[i+1])
                R[i] = 0;
        }
        
        int m = 0;
        int res = 0;
        for(int i=0; i<size; i++){
            if(R[i] == 0){
                res+=m;
                m=0;
            }
            m = max(m,R[i]-prices[i]);
        }
        
        return res;     
    }
};