class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
    if(costs.empty() || costs[0].empty()) return 0;
    int n = costs.size();
    vector<vector<int>>DP(n, vector<int>(costs[0].size(), INT_MAX));
    
    DP[0][0] = costs[0][0];
    DP[0][1] = costs[0][1];
    DP[0][2] = costs[0][2];
    
    for(int i=1; i<n; i++){
        DP[i][0] = costs[i][0] + min(DP[i-1][1],DP[i-1][2]);
        DP[i][1] = costs[i][1] + min(DP[i-1][0],DP[i-1][2]);
        DP[i][2] = costs[i][2] + min(DP[i-1][0],DP[i-1][1]);
    }
    
    return min(min(DP[n-1][0], DP[n-1][1]), DP[n-1][2]);
        
    }
};