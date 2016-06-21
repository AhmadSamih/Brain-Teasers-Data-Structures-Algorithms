class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>>DP(rows, vector<int>(cols,0));
    int _max=0;
    
    for(int i=0;  i<rows; i++) { DP[i][0] = matrix[i][0] - '0'; _max = max(DP[i][0],_max);}
    for(int j=0;  j<cols; j++) {DP[0][j] = matrix[0][j] -'0'; _max = max(DP[0][j],_max);}
    
    for(int i=1;  i<rows; i++){
        for(int j=1; j<cols; j++){
            DP[i][j] = matrix[i][j] - '0';
            DP[i][j] += (-DP[i][j])&(min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1])));
            _max = max(DP[i][j],_max);
        }
    }
    return _max*_max;
    }
};