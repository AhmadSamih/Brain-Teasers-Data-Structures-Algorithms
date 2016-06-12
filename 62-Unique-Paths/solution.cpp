class Solution {
public:
    int uniquePaths(int m, int n) {
        int xdim = m;
        int ydim = n;
        
        vector<vector<int>> DP(xdim, vector<int>(ydim, 0));
        DP[0][0]=1;
        
        for(int i = 1; i<xdim; i++){
            DP[i][0] = DP[i-1][0];
        }
        for(int j =1; j<ydim; j++){
            DP[0][j] = DP[0][j-1];
        }

        for(int i=1; i<xdim; i++){
            for(int j=1;j<ydim;j++){
                DP[i][j] = DP[i][j-1] + DP[i-1][j];
            }
        }
        return DP[xdim-1][ydim-1];
    }
};

