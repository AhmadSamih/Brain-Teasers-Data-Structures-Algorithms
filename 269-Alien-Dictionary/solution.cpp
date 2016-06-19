class Solution {
public:

    string res;
    //define a graph
    unordered_map<char,unordered_set<char>> G;
    unordered_set<int>cyc;
    unordered_map<char, bool>visited;

    bool topologicalSortUtil(char n)
    {
        if(cyc.count(n)) return true;
        if(visited[n]) return false;
        visited[n] = true; 
        
        cyc.insert(n);
        for(auto itr=G[n].begin(); itr!=G[n].end(); itr++){
             bool cycle = topologicalSortUtil(*itr);
             if(cycle)return true;
        }
        cyc.erase(n);
        
        res+=n;
        return false;
    }

    string topologicalSort()
    {
        for(auto itr=G.begin(); itr!=G.end(); itr++){
            bool cycle = topologicalSortUtil(itr->first);
            if(cycle) return "";
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string alienOrder(vector<string>& words) {
        if(words.size()==1) return words.front();
        for(int i = 0; i<words.size()-1; i++){
            string w1 = words[i]; string w2 = words[i+1]; int found = 0;
            for(int j=0; j<max(w1.size(), w2.size()); j++){
                if(j<w1.size() && G.count(w1[j])==0)G[w1[j]] = unordered_set<char>();
                if(j<w2.size() && G.count(w2[j])==0)G[w2[j]] = unordered_set<char>();
                if(j<w1.size() && j<w2.size() && w1[j] != w2[j] && !found){
                    G[w1[j]].insert(w2[j]);
                    found =1;
                }
            }
        }
        return topologicalSort();
    }
};
