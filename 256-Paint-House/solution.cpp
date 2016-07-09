class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
    if(costs.empty() || costs[0].empty()) return 0;
    int n = costs.size();
    vector<vector<int>>DP(n, vector<int>(2, INT_MAX));
    
    DP[0][0] = costs[0][0];
    DP[0][1] = costs[0][1];
    DP[0][2] = costs[0][2];
    if(n==1) return min(min(DP[0][0], DP[0][1]), DP[0][2]);
    
    for(int i=1; i<n; i++){
        DP[1][0] = costs[i][0] + min(DP[0][1],DP[0][2]);
        DP[1][1] = costs[i][1] + min(DP[0][0],DP[0][2]);
        DP[1][2] = costs[i][2] + min(DP[0][0],DP[0][1]);
        
        DP[0][0] =  DP[1][0];
        DP[0][1] =  DP[1][1];
        DP[0][2] =  DP[1][2];
    }
    
    return min(min(DP[1][0], DP[1][1]), DP[1][2]);
        
    }
};