class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0 || board[0].size()==0) return false;

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0])
                    if(DFS(i, j, 1, word, board)) return true;
            }
        }
        return false;
    }
    
    
    bool DFS(int i, int j, int idx, string &word, vector<vector<char>>& board){
        if(idx == word.size())
            return true;

        char c = board[i][j];
        board[i][j] = '#';
        
        int dir[][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        for(auto &k:dir){
            int x = i+ k[0];
            int y = j + k[1];
            if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y] == word[idx]){
                if(DFS(x, y, idx+1, word, board)) return true;
            }
        }
        
        board[i][j] = c;
        return false;
    }
};