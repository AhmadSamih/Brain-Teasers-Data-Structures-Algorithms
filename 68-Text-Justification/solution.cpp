class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        //check 2d iterators again
        
        vector<int>words_per_line;
        vector<int>chars_per_line;
        
        int wrds = 0;
        int chars = 0;
        int prev_idx =0;
        for(int i=0; i<=words.size();i++){
            int spaces = i-prev_idx;
            if( i<words.size() &&(chars + words[i].size() + spaces) <= maxWidth){
                wrds+=1;
                chars+=words[i].size();
            }else{
                words_per_line.push_back(wrds);
                chars_per_line.push_back(chars);
                prev_idx = i;
                if(i<words.size()){
                    wrds = 1;
                    chars = words[i].size();
                }
            }
        }
        

        vector<string>res;        
        int wrd_idx = 0;
        for(int i=0; i<words_per_line.size();i++){//num lines
            string str = "";
            int spaces = maxWidth - chars_per_line[i];
            int ending = 0; 
            int extra, sp_per_wrd;
    
            if(i == words_per_line.size()-1) {
                sp_per_wrd = 1;
                ending = spaces - (words_per_line[i]-1);
                extra=0;
            }else{
                if(words_per_line[i] ==1 ) sp_per_wrd = spaces;
                else {sp_per_wrd = spaces/(words_per_line[i]-1);
                    extra = spaces%(words_per_line[i]-1);
                }
            }

            if(words_per_line[i]<=2  && (i!=words_per_line.size()-1)){
                str+=words[wrd_idx++];
                while(spaces) {str+=" "; spaces--;}
                if(words_per_line[i]==2)str+=words[wrd_idx++];
            }else{
                for(int k=0; k<words_per_line[i];k++){
                    str+=words[wrd_idx++];
                    if(k == words_per_line[i]-1) continue;
                    for(int kk=0; kk<sp_per_wrd;kk++)str+= " ";
                    if(extra){ str+= " "; extra--;}
                }
                
                while(ending){str+=" "; ending--;}
            }

            res.push_back(str);
        }

        return res;
    }
};