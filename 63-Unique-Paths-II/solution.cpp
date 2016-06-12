class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())return 0;
        int xdim = obstacleGrid.size();
        int ydim = obstacleGrid[0].size();

        //convert to Dynamic Programming solution
        vector<vector<int>> DP(xdim, vector<int>(ydim, 0));
        if(!obstacleGrid[0][0]) DP[0][0]=1;
        
        for(int i = 1; i<xdim; i++){
            if(!obstacleGrid[i][0])
                DP[i][0] = DP[i-1][0];
        }
        for(int j =1; j<ydim; j++){
            if(!obstacleGrid[0][j])
                DP[0][j] = DP[0][j-1];
        }

        for(int i=1; i<xdim; i++){
            for(int j=1;j<ydim;j++){
                if(!obstacleGrid[i][j])
                    DP[i][j] = DP[i][j-1] + DP[i-1][j];
            }
        }
        return DP[xdim-1][ydim-1];
    }
};

