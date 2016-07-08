class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>DP(amount+1,INT_MAX);
        for(int i=0; i<coins.size(); i++){
            if(amount<coins[i]) continue;
            DP[coins[i]] = 1;
        }
        
        DP[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size();j++){
                if(i<coins[j] || DP[i-coins[j]] == INT_MAX) continue;
                DP[i] = min(DP[i - coins[j]] + DP[coins[j]], DP[i]);
            }
        }
        if(DP[amount]==INT_MAX) return -1;
        else return DP[amount];
    }
};