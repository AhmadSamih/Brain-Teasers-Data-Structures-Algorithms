class Solution {
public:

    string res;
    struct vertix{
        vertix* adj[26];
        char v;
        vertix(char _v){
            for(int i=0; i<26; i++){
                adj[i] = NULL;
            }
            v = _v;
        }
    };
    unordered_map<int, vertix*>cache;
    int cycle = 0;
    unordered_set<int>cyc;
    void topologicalSortUtil(vertix* v, unordered_map<vertix*, bool> &visited, stack<char> &Stack)
    {
        //how to detect a cycle
        //cout << v->v << " ";
        if(cyc.count(v->v)) {cycle=1; return;}
        
        if(visited[v]) return;
        visited[v] = true; 
        cyc.insert(v->v);
     
        for(int i =0; i<26; i++)
            if(v->adj[i])
                topologicalSortUtil(v->adj[i], visited, Stack);
    
        //cout<<endl;
        cyc.erase(v->v);
        Stack.push(v->v);
    }

    void topologicalSort()
    {
        stack<char> Stack;
        unordered_map<vertix*, bool>visited;

        for(auto itr=cache.begin(); itr!=cache.end(); itr++)
         // if (visited[itr->second] == false)
         {
            topologicalSortUtil(itr->second, visited, Stack);
          }

        while (!Stack.empty())
        {
            res+=Stack.top();
            Stack.pop();
        }
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
  
        topologicalSort();
        if(cycle) return "";
        return res ;
    }
};
