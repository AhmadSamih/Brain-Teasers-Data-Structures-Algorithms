class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>DP(amount+1,INT_MAX);

        DP[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size();j++){
                if(i<coins[j] || DP[i-coins[j]] == INT_MAX) continue;
                DP[i] = min(DP[i - coins[j]] + 1, DP[i]);
            }
        }
        if(DP[amount]==INT_MAX) return -1;
        else return DP[amount];
    }
};

//try a third solution with math

