class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0) return 0;
    vector<vector<int>>DP(matrix.size(), vector<int>(matrix[0].size(),0));
    int _max=0;
    for(int i=0;  i<matrix.size(); i++) { DP[i][0] = matrix[i][0] - '0'; _max = max(DP[i][0],_max);}
    for(int j=0;  j<matrix[0].size(); j++) {DP[0][j] = matrix[0][j] -'0'; _max = max(DP[0][j],_max);}
    for(int i=1;  i<matrix.size(); i++){
        for(int j=1; j<matrix[i].size(); j++){
            DP[i][j] = matrix[i][j] - '0';
            DP[i][j] += (-DP[i][j])&(min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1])));
            _max = max(DP[i][j],_max);
        }
    }
    return _max*_max;
    }
};