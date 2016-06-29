class Solution {
public:

    struct TrieNode{
      TrieNode* p[26];  
      string word;
      TrieNode(){
          for(auto &x : p)x=NULL;
          word.clear();
      }
    };

    TrieNode * head;
    
    void add_word(string w){
        TrieNode *tmp = head;
        for(int i= 0; i<w.size(); i++){
            int pos = w[i]- 'a';
            if(tmp->p[pos] == NULL) tmp->p[pos] = new TrieNode();
            tmp = tmp->p[pos];
        }
        tmp->word = w;
    }

    void dfs(TrieNode *n, int x, int y, int xdim, int ydim, vector<vector<char>>&board, vector<string>& res){
        if(!n->word.empty()){
            res.push_back(n->word);
            n->word.clear(); //invalidate so we don't match on it again to prevent duplicates
        }
        
        char c = board[x][y];
        board[x][y] = '*'; //mark as visited
        
        int nbrs[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0 ;i<4; i++){
            int d0 = x + nbrs[i][0];
            int d1 = y + nbrs[i][1];
            if(d0>=0 && d0<xdim && d1>=0 && d1<ydim && board[d0][d1]!='*' && n->p[board[d0][d1]-'a']){
                dfs(n->p[board[d0][d1]-'a'], d0 , d1, board.size(), board[0].size(), board,res);
            }
        }
        board[x][y] = c; //backtrack
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(!board.size() || !board[0].size() || !words.size())return res;
        head = new TrieNode();
        for(auto &x:words) add_word(x);

        for(int i=0 ;i<board.size(); i++){
            for(int j=0; j<board[0].size();j++){
                int c = board[i][j]-'a';
                if(head->p[c])
                    dfs(head->p[c], i , j, board.size(), board[0].size(), board,res);
            }
        }
        return res;
        
    }
};