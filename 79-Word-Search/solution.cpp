class Solution {
public:
    string word;
    vector<vector<char>> * _board;
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0 || board[0].size()==0) return false;
        
        _board = &board;  this->word = word;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0])
                    if(DFS(i, j, 1)) return true;
            }
        }
        return false;
    }
    
    
    bool DFS(int i, int j, int idx){
        if(idx == word.size())
            return true;

        char c = (*_board)[i][j];
        (*_board)[i][j] = '#';
        
        int dir[][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        for(auto &k:dir){
            int x = i+ k[0];
            int y = j + k[1];
            if(x>=0 && y>=0 && x<_board->size() && y<(*_board)[0].size() && (*_board)[x][y] == word[idx]){
                if(DFS(x, y, idx+1)) return true;
            }
        }
        
        (*_board)[i][j] = c;
        return false;
    }
};