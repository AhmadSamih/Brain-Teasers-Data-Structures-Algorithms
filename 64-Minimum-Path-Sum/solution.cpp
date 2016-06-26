class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int x = grid.size(); int y; if(x) y =  grid[0].size(); else return 0;
        int DP[x][y]= {0};
        
        DP[0][0] = grid[0][0];
        for(int i=1; i<x; i++){
            DP[i][0] = DP[i-1][0] + grid[i][0];
        }
        for(int j=1; j<y; j++){
            DP[0][j] = DP[0][j-1] + grid[0][j];
        }

        for(int i=1; i<x; i++)
            for(int j=1; j<y;j++){
                DP[i][j] = grid[i][j] + min(DP[i-1][j], DP[i][j-1]);
            }

        return DP[x-1][y-1];
    }
};