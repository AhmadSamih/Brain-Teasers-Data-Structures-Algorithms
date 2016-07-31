class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>stk;
        char * dup = strdup(path.c_str());
        char * token = strtok(dup, "/");
        
        while(token){
            string tmp = string(token);
            if(tmp == ".." && !stk.empty()) stk.pop();
            if(tmp != "" && tmp != "." && tmp != "..") stk.push(tmp);
            token = strtok(NULL, "/");
        }
        if(stk.empty()) return "/";
        
        string result;
        while(!stk.empty()){
            result.insert(0,"/"+stk.top());
            stk.pop();
        }
        return result;
    }
};