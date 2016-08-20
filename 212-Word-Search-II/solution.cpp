class Solution {
public:
    struct trie{
      trie* p[26];
      string word;
      trie(){
        for(auto &x:p)
            x = NULL;
        word.clear();
      }
    };
     void add_word(string w, trie* tmp){
         trie*head = tmp;
        for(int i=0;i<w.size();i++){
            int c = w[i]-'a';
            if(!head->p[c])
                head->p[c] = new trie();
            head = head->p[c];
        }
        head->word = w;
    }
   

    vector<string> res;
    void DFS(vector<vector<char>>& board, int x, int y, int xx, int yy, trie*head){
        if(!head->word.empty()){
            res.push_back(head->word);
            head->word.clear();
        }

        char c = board[x][y];
        board[x][y] = '#';
        
        int dim[][2] = {{-1,0},{1,0},{0,1},{0,-1}};        
        for(int i=0; i<4; i++){
            int xp = x+ dim[i][0];
            int yp = y+ dim[i][1];
            if(xp < xx && xp>=0 && yp>=0 && yp<yy && board[xp][yp]!='#' && head->p[board[xp][yp]-'a']){
                DFS(board, xp, yp, xx, yy,head->p[board[xp][yp]-'a']);
            }
        }
        
        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size()==0 || board[0].size()==0 || words.empty()) return res;
        
        trie* head = new trie();
        for(auto &w:words)
            add_word(w,head);

        int x = board.size();
        int y = board[0].size();
        
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(head->p[board[i][j]-'a'])
                    DFS(board, i, j, x, y, head->p[board[i][j]-'a']);
            }
        }
        
        return res;
    }
};
