class Solution {
public:
    string simplifyPath(string path) {
        
        char * dup = strdup(path.c_str());
        char * token = strtok(dup, "/");
        stack<string>stk;
        while(token){
            if(string(token) == ".."){
                if(!stk.empty())
                    stk.pop();
            }else if(string(token) != "" && string(token) != ".")
                stk.push(string(token));
            token = strtok(NULL, "/");
        }

        string result;
        result.clear();
        if(stk.empty()) return "/";
        while(!stk.empty()){
            result.insert(0,"/"+stk.top());
            stk.pop();
        }
        return result;
    }
};