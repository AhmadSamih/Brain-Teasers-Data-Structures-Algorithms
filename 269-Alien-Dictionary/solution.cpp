class Solution {
public:
    
    stack<char> stk;
    unordered_set<char>cycle;
    unordered_map<char, bool>v;
    unordered_map<char,unordered_set<char>>g;
    
    bool dfs(char c){
        if(cycle.count(c))
            return true;
        if(v[c])
            return false;
        
        cycle.insert(c);            
        v[c] =  true;
        
        for(auto itr=g[c].begin(); itr!=g[c].end(); itr++){
            if(dfs(*itr))
                return true;
        }
        cycle.erase(c);
        stk.push(c);
        
        return false;
    }

    string alienOrder(vector<string>& words) {
        
        if(words.empty()) return "";
        if(words.size() == 1) return words[0];
        
        for(int i=1; i<words.size(); i++){
            string w1 = words[i-1];
            string w2 = words[i];
            int found = 0;
            for(int j=0; j<max(w1.size(), w2.size()); j++){
                if(j<w1.size() && !g.count(w1[j])) g[w1[j]] = unordered_set<char>();
                if(j<w2.size() && !g.count(w2[j])) g[w2[j]] = unordered_set<char>();
                if(j<w1.size() && j<w2.size() && !found && w1[j]!=w2[j]){
                    found =1;
                    g[w1[j]].insert(w2[j]);
                }
            }
        }
        
        for(auto itr=g.begin(); itr!=g.end(); itr++){
            if(dfs(itr->first)) //detect a cycle
                return "";
        }
        
        string res = "";
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
