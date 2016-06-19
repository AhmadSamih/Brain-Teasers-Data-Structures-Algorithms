class Solution {
public:
    //build a trie out of the words needed
    struct trieNode{
      trieNode* n[26];
      string word;
      trieNode(){
          for(auto &i:n) i = NULL; //note the reference here
      }
    };
    
    struct trie{
        trieNode * head;
        trie():head(new trieNode()){}
        void insert(string word){
            trieNode *p = head;
            for(auto &i:word){
                int c = i - 'a';
                if(!p->n[c]) p->n[c] = new trieNode();
                p = p->n[c];
            }
            p->word = word;
        }
    };

    vector<string>res;
    vector<vector<int>>visited;
    void dfs(int i, int j, trieNode *p, int xdim, int ydim, vector<vector<char>>& board){
        if(visited[i][j]) return;
        
        if(!p->word.empty()){
            res.push_back(p->word);
            p->word.clear();
            //shouldn't return because this might be a partial word matching.
        }

        //traverse all directions
        visited[i][j] = 1;
        int dirs[][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(auto &dir:dirs){
            int x = i+dir[0]; int y = j+dir[1];
            if(x>=0 && x<xdim && y>=0 && y<ydim && p->n[board[x][y]-'a']){
                dfs(x, y, p->n[board[x][y]-'a'], xdim, ydim, board);
            }
        }
        visited[i][j] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        if(!board.size() || !board[0].size() || !words.size()) return res;
        
        trie T;

        //fill up the trie
        for(auto &w:words) T.insert(w);

        visited.resize(board.size(), vector<int>(board[0].size(),0));
        for(int i=0 ;i<board.size();i++){
            for(int j=0; j<board[i].size();j++){
                if(T.head->n[board[i][j] -'a'])
                    dfs(i, j, T.head->n[board[i][j]-'a'], board.size(), board[i].size(), board);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};