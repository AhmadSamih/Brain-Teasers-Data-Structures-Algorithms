class Solution {
public:

    bool DFS(string word, int idx, vector<vector<char>>& board, int x, int y, int xx, int yy){
        
        if(idx == word.size())
            return true;
        
        char c = board[x][y];
        board[x][y] = '#';
        
        int dim[][2] = {{-1,0},{1,0},{0,1},{0,-1}};        
        for(int i=0; i<4; i++){
            int xp = x+ dim[i][0];
            int yp = y+ dim[i][1];
            if(xp < xx && xp>=0 && yp>=0 && yp<yy && board[xp][yp] == word[idx]){
                if(DFS(word, idx+1, board, xp, yp, xx, yy))
                    return true;
            }
        }
        
        board[x][y] = c;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0 || board[0].size()==0 || word.empty()) return false;
        
        int x = board.size();
        int y = board[0].size();
        
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(board[i][j] == word[0])
                    if(DFS(word, 1, board, i, j, x, y))
                        return true;
            }
        }
        
        return false;
    }
};