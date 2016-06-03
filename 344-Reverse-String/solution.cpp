class Solution {
public:
    string reverseString(string s) {
       if((s.size()) <= 1) return s;
       
       //let's reverse it in place, shall we?
       int e = s.size()-1;
       int b = 0;
       
       while(b<e){
           shuffle(s[b], s[e]);
           b ++;
           e --;
       }
       
       return s;
      
    }
    
    void shuffle(char & f, char & s){
        char tmp = f;
        f = s;
        s = tmp;
    }
};