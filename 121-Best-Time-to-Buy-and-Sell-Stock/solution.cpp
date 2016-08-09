class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //the difference between this and kadanes, is we start at 0 (no transaction could be done), in Kadane however, there has
        //to be a minimum, which actually could be negative.
        
        /*int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur + prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
        */
        int size = prices.size();
        vector<int>R(size,0);
        for(int i=size-2; i>=0;i--){
            R[i] = max(prices[i+1], R[i+1]);
        }
        int m = 0;
        for(int i=0; i<size; i++){
            m = max(m,R[i]-prices[i]);
        }
        return m;   
    }
};