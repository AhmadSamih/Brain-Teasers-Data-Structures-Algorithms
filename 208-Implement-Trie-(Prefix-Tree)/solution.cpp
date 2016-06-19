class TrieNode {
public:
    // Initialize your data structure here.
      TrieNode* child[26];
      bool isword;
      TrieNode(){
          for(auto &i:child) i = NULL; //note the reference here
          isword = false;
      }
};

class Trie {
public:
    Trie() {
        head = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = head;
        for(auto &i:word){
            int c = i - 'a';
            if(!p->child[c]) p->child[c] = new TrieNode();
            p = p->child[c];
        }
        p->isword = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = head;
        for(auto &i : word){
            int c = i - 'a';
            if(!p->child[c]) return false;
            p= p->child[c];
        }
        return (p->isword);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = head;
        for(auto &i : prefix){
            int c = i - 'a';
            if(!p->child[c]) return false;
                p = p->child[c];
        }
        return true;
    }

private:
    TrieNode* head;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");