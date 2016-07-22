class Solution {
public:
    void reverseWords(string &s) {

      stack<string> stk;
      std::size_t begin = 0;
      std::size_t end = 0;
      while(end != string::npos){
        begin = s.find_first_not_of(' ',end);
        if(begin == string::npos) break;
        end = s.find_first_of(' ',begin+1);
        stk.push(s.substr(begin,end-begin));
      }    
      s.clear();
      while(!stk.empty()){
        s.append(stk.top());
        if(stk.size() >1) s.append(" ");
        stk.pop();
      }
    }        
};