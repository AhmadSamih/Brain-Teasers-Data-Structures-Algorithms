class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0) return 0;
        vector<vector<int>>DP(matrix.size(), vector<int>(matrix[0].size(),0));
        
        int max = 0;
        for(int i = 0;i <matrix.size();i++){
            if(matrix[i][0]=='1'){
                DP[i][0] = 1;
                max = 1;
            }
        }
        for(int i = 0;i <matrix[0].size();i++){
            if(matrix[0][i]=='1'){
                DP[0][i] = 1;
                max = 1;
            }
        }
        
        for(int i=1;  i<matrix.size(); i++){
            for(int j=1; j<matrix[i].size(); j++){
                if(matrix[i][j]=='1'){
                    DP[i][j] = min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1])) + 1;
                    max = max<DP[i][j] ? DP[i][j] : max;
                }
            }
        }

    return max*max;
    }
};