class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int>words_per_line;
        vector<int>chars_per_line;
        
        int wrds = 0;
        int chars = 0;
        int prev_idx =0;
        for(int i=0; i<words.size();i++){
            if((chars + words[i].size() + (i-prev_idx)) <= maxWidth){
                wrds+=1;
                chars+=words[i].size();
            }else{
                words_per_line.push_back(wrds);
                chars_per_line.push_back(chars);
                prev_idx = i; wrds = 1;
                chars = words[i].size();
            }
        }
        words_per_line.push_back(wrds);
        chars_per_line.push_back(chars);
        

        vector<string>res;        
        int wrd_idx = 0;
        string str = "";
        
        for(int i=0; i<words_per_line.size();i++){//num lines
            
            int spaces = maxWidth - chars_per_line[i];
            int sp_per_wrd = spaces/(words_per_line[i] == 1? 1 : words_per_line[i]-1);
            int extra = spaces % (words_per_line[i] == 1? 1 : words_per_line[i]-1);

            for(int k=0; k<words_per_line[i]-1;k++){
                str.append(words[wrd_idx++]);
                str.append(i<words_per_line.size()-1 ? sp_per_wrd : 1, ' ');
                if(extra && i<words_per_line.size()-1)
                    str.append(" "), extra--;
            }
            str.append(words[wrd_idx++]);
            if(words_per_line[i]==1)
                str.append(sp_per_wrd, ' ');
            else if(i == words_per_line.size()-1) 
                str.append(spaces - (words_per_line[i]-1), ' ');

            res.push_back(str);
            str.clear();
        }

        return res;
    }
};