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
                if(matrix[i][j]=='0')
                    DP[i][j] = 0;
                else{
                    int Lj = DP[i][j-1];
                    int Li = DP[i-1][j];
                    if(Li != Lj){
                        DP[i][j] = 1 + min(Li,Lj);
                    }else{
                        if(matrix[i-Li][j-Li] == '1')DP[i][j] = 1+ Li;
                        else DP[i][j] = Li;
                    }
                    max = max<DP[i][j] ? DP[i][j] : max;
                }
            }
        }
   /*     
        for(int i=0;  i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                cout << DP[i][j] << " ";
            }
            cout << endl;
        }
    */
    return max*max;
    }
};