class Solution {
public:
    string word;
    vector<vector<char>> * _board;
    bool exist(vector<vector<char>>& board, string word) {
        _board = &board;
        this->word = word;
        if(board.size()==0 || board[0].size()==0) return false;
        //handle word empty case
        
        bool found = false;
        int x = board.size();
        int y = board[0].size();
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(board[i][j] == word[0])
                    DFS(i, j, 1, found);
                    if(found) return true;
            }
        }
        return false;
    }
    //DFS
    void DFS(int i, int j, int idx, bool & found){
        if(idx == word.size()){
            found = true;
            return;
        }
        if(idx > word.size())
            return;        
        
        char c = (*_board)[i][j];
        (*_board)[i][j] = '#';
        
        int dir[][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int k=0; k<4; k++){
            int x = i+ dir[k][0];
            int y = j + dir[k][1];
            if(x>=0 && y>=0 && x<_board->size() && y<(*_board)[0].size() && (*_board)[x][y] == word[idx] && (*_board)[x][y]!='#'){
                DFS(x, y, idx+1,found);
                if(found == true)
                    return;
            }
        }
        
        (*_board)[i][j] = c;
    }
};