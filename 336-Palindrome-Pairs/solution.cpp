class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {

    vector<vector<int>> res;
    //populate the words in a hash map
    unordered_map<string, int>wrd_idx;
    for(int i=0; i<words.size();i++){
        wrd_idx[words[i]] = i;
    }

    //substr, reverse, 
    vector<int>set(2);
    for(int i =0; i<words.size();i++){
        int len = words[i].size();
        for(int j=0; j<=len; j++){
            string left = words[i].substr(0,j);
            string right = words[i].substr(j);
            string rleft = left;
            string rright = right;
            reverse(rleft.begin(), rleft.end());
            reverse(rright.begin(), rright.end());
           
            if(wrd_idx.find(rleft)!= wrd_idx.end() && wrd_idx[rleft]!=i && (right==rright)){
                set[0] = i;
                set[1] = wrd_idx[rleft];
                res.push_back(set);
            }

            if(j!=0 && wrd_idx.find(rright)!= wrd_idx.end() && wrd_idx[rright]!=i && (left==rleft)){
                set[0] = wrd_idx[rright];
                set[1] = i;
                res.push_back(set);
            }
        }
    }
    return res;
    }

    bool isPalindrome(string s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        return (s == tmp);
    }
};