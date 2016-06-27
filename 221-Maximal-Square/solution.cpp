class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int x = matrix.size();
        if(x == 0) return 0;
        int y = matrix[0].size();
        int max = INT_MIN;
        vector<vector<int>>DP(x, vector<int>(y,0));
        
        for(int i=0; i<x; i++){
            DP[i][0] = matrix[i][0]-'0';
            if(max < DP[i][0]) max = DP[i][0];
        }

        for(int j=0; j<y; j++){
            DP[0][j] = matrix[0][j]-'0';
            if(max < DP[0][j]) max = DP[0][j];
        }
        
        
        for(int i = 1; i < x; i++){
            for(int j = 1; j< y; j++){
                if(matrix[i][j]-'0')
                    DP[i][j] = 1 + min(DP[i-1][j-1], min(DP[i-1][j],DP[i][j-1]));
                else
                    DP[i][j] = 0;
                if(max < DP[i][j]) max = DP[i][j];
            }
        }
        return max*max;
    }
};