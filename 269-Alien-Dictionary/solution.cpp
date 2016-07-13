class Solution {
public:

    string res;
    //define a graph
    unordered_map<char,unordered_set<char>> G;
    unordered_set<int>cyc;
    unordered_map<char, bool>visited;

    bool topologicalSortUtil(char n)
    {
        if(cyc.find(n) != cyc.end()) return true; //this has to be checked first, to detect cycles
        if(visited[n]) return false; //then if no cycle detected, but node is visited, we return
        
        visited[n] = true; 
        
        cyc.insert(n);
        for(auto itr=G[n].begin(); itr!=G[n].end(); itr++){
             if(topologicalSortUtil(*itr))//can't call it based on visisted, because we need to detect cycle first
                 return true;
        }
        cyc.erase(n);
        
        res+=n;
        return false;
    }

    string alienOrder(vector<string>& words) {
        if(words.size()==1) return words.front();
        for(int i = 0; i<words.size()-1; i++){
            string w1 = words[i]; string w2 = words[i+1]; int found = 0;
            for(int j=0; j<max(w1.size(), w2.size()); j++){
                if(j<w1.size() && G.find(w1[j])==G.end())G[w1[j]] = unordered_set<char>();
                if(j<w2.size() && G.find(w2[j])==G.end())G[w2[j]] = unordered_set<char>();
                if(j<w1.size() && j<w2.size() && w1[j] != w2[j] && !found){
                    G[w1[j]].insert(w2[j]);
                    found =1;
                }
            }
        }
        
        for(auto itr=G.begin(); itr!=G.end(); itr++){
            if(topologicalSortUtil(itr->first))
                return "";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
