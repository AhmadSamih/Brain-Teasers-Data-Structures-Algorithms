class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>DP(amount+1,INT_MAX);
        DP[0] = 0;
        for(int j=0; j<coins.size();j++){
            for(int i=coins[j]; i<=amount; i++){
                if(DP[i-coins[j]] == INT_MAX) continue;
                DP[i] = min(DP[i - coins[j]] + 1, DP[i]);
            }
        }
        if(DP[amount]==INT_MAX) return -1;
        else return DP[amount];
    }
};