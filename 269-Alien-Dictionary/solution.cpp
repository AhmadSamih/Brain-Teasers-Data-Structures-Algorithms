class Solution {
public:

    stack<char>stk;
    unordered_map<char, bool>visited;
    unordered_map<char,unordered_set<char>>dict;
    unordered_set<char>cycle;
    bool dfs(char c){
        if(cycle.count(c)) return false;
        if(visited[c]) return true;
        visited[c] = 1;
        cycle.insert(c);
        for(auto itr=dict[c].begin(); itr!=dict[c].end(); itr++){
            if(!dfs(*itr)){
                return false;
            }
        }
        cycle.erase(c);
        stk.push(c);
        return true;
    }

    string alienOrder(vector<string>& words) {

        if(words.empty()) return "";
        if(words.size() == 1) return words[0];
        for(int i=1; i<words.size();i++){
            string w1 = words[i-1];
            string w2 = words[i];
            bool found = 0;
            for(int j=0; j<max(w1.size(), w2.size()); j++){
                if(j<w1.size() && !dict.count(w1[j])) dict[w1[j]] = unordered_set<char>();
                if(j<w2.size() && !dict.count(w2[j])) dict[w2[j]] = unordered_set<char>();
                if(j<w1.size() && j<w2.size() && !found && w1[j]!=w2[j]){
                    found = true;
                    dict[w1[j]].insert(w2[j]);
                }
            }
        }
        
        for(auto itr=dict.begin(); itr!=dict.end(); itr++){
            char c = itr->first;
                if(!dfs(c))
                    return "";
        }
        
        string res = "";
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        
        return res;
    }
};