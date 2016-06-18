class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int num_chars = 0;
        vector<vector<int>>res;
        vector<string> tmp; if(words.empty()) return tmp;
        vector<int>indices;
        vector<int>num_chars_v;
        for(int next=0; next<words.size();next+=indices.size()){
            indices.clear();
            num_chars = 0;
            for(int i=next;i<words.size();i++){
                int num_spaces = i - next;
                if( (num_chars + words[i].size() + num_spaces) <= maxWidth){
                    num_chars += words[i].size();
                    indices.push_back(i);
                }else{
                    break;
                }
            }
            num_chars_v.push_back(num_chars);
            res.push_back(indices);
        }
        int w_idx=0;
        for(int i=0;i<res.size();i++){
            int spaces = maxWidth - num_chars_v[i];
            int num_words = res[i].size();
            string s;
             if(num_words==1){
                s =words[w_idx++]; 
                int itr=0; while(itr<spaces){s+=" "; itr++;};
                tmp.push_back(s);
            }if(num_words >= 2){
                int per_char_spaces = spaces/(num_words-1);
                int extra_spaces = spaces - per_char_spaces*(num_words-1);
                int end_spaces = 0;
                if(i == res.size()-1){
                    per_char_spaces = 1;
                    extra_spaces=0;
                    end_spaces = spaces - (num_words-1);
                }
                for(int ix=0; ix<num_words-1;ix++){
                    s+=words[w_idx++];
                    int itr=0; while(itr<(per_char_spaces+(extra_spaces>0?1:0))){s+=" "; itr++;};
                    extra_spaces--;
                }
                s+=words[w_idx++];
                int itr=0; while(itr<end_spaces){s+=" "; itr++;};
                tmp.push_back(s);
            }
        }
        return tmp;
    }
};