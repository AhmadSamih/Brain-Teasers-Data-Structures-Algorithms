class WordDictionary {
public:
  
    WordDictionary(){
      head= new TrieNode();
    }
  
    struct TrieNode{
      TrieNode* child[26];  
      string word;
      TrieNode(){
          for(auto &x : child)
            x=NULL;
          word.clear();
      }
    };

    TrieNode * head;

    // Adds a word into the data structure.
    void addWord(string w) {
        TrieNode *tmp = head;
        for(uint32_t i= 0; i<w.size(); i++){
            int pos = w[i] - 'a';
            if(tmp->child[pos] == NULL) 
                tmp->child[pos] = new TrieNode();
            tmp = tmp->child[pos];
        }
        tmp->word = w;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    string word;
    bool search(string word) {
        this->word = word;
        return df(0, head);
    }
    
    bool df(int idx, TrieNode *p){
        for(uint32_t i=idx; i<word.size(); i++){
            if(word[i] != '.'){
                int c = word[i] - 'a';
                if(!p->child[c]) 
                    return false;
                p = p->child[c];
            }else{
                for(auto &x:p->child)
                    if(x != NULL && df(i+1, x))
                        return true;
                return false;
            }
        }
        return (!p->word.empty());
    }
};