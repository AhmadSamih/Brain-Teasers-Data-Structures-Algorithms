class Solution {
public:
    vector<string> vec;
    string path;
    vector <bool> used;

    vector<string> generatePalindromes(string s) {
        int odds =0;
        unordered_map<char, int>m;
        for(auto &x:s){
            m[x]++;
        }

        for(auto itr=m.begin() ;itr!=m.end(); itr++){
            if((itr->second)&0x1){odds++;}
        }
        if(odds>1) return vec;
        
        string new_str = "";
        
        char o;
        int st = 0;
        for(int i=0 ;i<s.size();i++){
            
            int num = m[s[i]];
            if(!st && (num&0x1)){st= 1; o = s[i];m[s[i]]--;}
            if(m[s[i]] <=0) continue;
             new_str+=s[i];
             m[s[i]]-=2;
        }
        if(odds>1) return vec;
        
        used.resize(s.size(),false);
        sort(new_str.begin(), new_str.end());
        DF(new_str, new_str.size(),0, o, odds);
        return vec;
    }
    
    void DF(string s, int size, int idx, char o, int odd){
        if(path.size() == size){
            string tmp = path;
            reverse(tmp.begin(), tmp.end());
            if(odd) vec.push_back(path+o+tmp);
            else vec.push_back(path+tmp);
            return;
        }else if(path.size()>size)
            return;
            
        for(int i=idx; i<size; i++){
            if(used[i] || (i>0 && s[i]==s[i-1] && !used[i-1]) ) continue;
            path += s[i];
            used[i] = true;
            DF(s,size, idx,o, odd);
            path.pop_back();
            used[i] = false;
        }
    }
  
};