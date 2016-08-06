class Solution {
public:
    int maxProfit(vector<int>& prices) {
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