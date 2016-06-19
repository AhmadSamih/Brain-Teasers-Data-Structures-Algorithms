class Solution {
public:

    string res;
    struct vertix{
        char v;
        vertix* adj[26];
        vertix(char _v){
            for(int i=0; i<26; i++){
                adj[i] = NULL;
            }
            v = _v;
        }
    };

    unordered_map<int, vertix*>cache;
    unordered_set<int>cyc;

    bool topologicalSortUtil(vertix* v, unordered_map<vertix*, bool> &visited, stack<char> &Stack)
    {
        if(cyc.count(v->v)) return true;
        
        if(visited[v]) return false;
        visited[v] = true; 
        cyc.insert(v->v);
     
        for(int i =0; i<26; i++)
            if(v->adj[i]){
             bool cycle = topologicalSortUtil(v->adj[i], visited, Stack);
             if(cycle)return true;
            }
    
        cyc.erase(v->v);
        Stack.push(v->v);
        return false;
    }

    bool topologicalSort()
    {
        stack<char> Stack;
        unordered_map<vertix*, bool>visited;

        for(auto itr=cache.begin(); itr!=cache.end(); itr++){
            bool cycle = topologicalSortUtil(itr->second, visited, Stack);
            if(cycle) return false;
        }

        while (!Stack.empty()){
            res+=Stack.top();
            Stack.pop();
        }
        return false;
    }
    
    string alienOrder(vector<string>& words) {
        if(words.size()==1)return words.front();
        vertix* v = NULL;
        for(int i = 0; i<words.size()-1; i++){
            string w1 = words[i]; string w2 = words[i+1];
            int found = 0;
            for(int j=0; j<max(w1.size(), w2.size()); j++){
                if(j<w1.size()){
                    if(cache[words[i][j]]==false)
                        cache[words[i][j]] = new vertix(words[i][j]); 
                    v = cache[words[i][j]];
                }
                if(j<w2.size()){
                    if(cache[words[i+1][j]]==false)
                        cache[words[i+1][j]] = new vertix(words[i+1][j]); 
                }

                if(j<w1.size() && j<w2.size() && w1[j] != w2[j] && !found){
                    v->adj[words[i+1][j]-'a'] = cache[words[i+1][j]];                
                    found =1;
                }
            }
        }
  
        bool cycle = topologicalSort();
        if(cycle) return "";
        return res ;
    }
};
