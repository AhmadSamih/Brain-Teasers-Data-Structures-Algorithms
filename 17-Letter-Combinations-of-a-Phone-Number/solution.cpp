class Solution {
public:
    vector<string> vec;
    string iStr;
    vector<string> letterCombinations(string digits){
        if(digits.size()<1)return vec;
        
        vector<string>c(256);
        c['2'] = "abc"; c['3'] = "def";
        c['4'] = "ghi"; c['5'] = "jkl";
        c['6'] = "mno"; c['7'] = "pqrs";
        c['8'] = "tuv"; c['9'] = "wxyz";
        
        vector<string>str(digits.size());
        int id = 0;
        for(auto i:digits){
            str[id++] = c[i];
        }
        iStr.resize(digits.size());
        recur(str, iStr, 0, digits.size());
        return vec;
    }
    void recur (vector<string>&str, string iStr, int i, int digits)
    {
        if (i >= digits){ //should we check for i ending?
            vec.push_back(iStr);
            return;
        }
        //loop over the size of the current digit's number of chars
        for(int x = 0; x < str[i].size(); x++){
            iStr[i] = str[i][x];
            recur (str, iStr, i+1, digits);
        }
    }
};