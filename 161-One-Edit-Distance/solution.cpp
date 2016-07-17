class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(abs(m-n)>1)return false;
        int edits = 0;
        int _min = min(m,n);
        for(int i=0; i<_min; i++){
            if(s[i]!=t[i]){
                edits++;
                //handle three cases
                string tmp1 = s.substr(i+1);
                string tmp2 = t.substr(i+1);
                //aaaabaaaa
                //aaaacaaaa
                
                string tmp3 = s.substr(i);
                string tmp4 = t.substr(i+1);
                //aaaaaaaa
                //aaaacaaaa

                string tmp5 = s.substr(i+1);
                string tmp6 = t.substr(i);
                //aaaabaaaa
                //aaaaaaaa
                //cout<<tmp1<<" "<<tmp2 <<" "<<tmp3<<" "<<tmp4<< " "<<tmp5<<" "<<tmp6<<endl;
                if(tmp1!=tmp2 && tmp3!=tmp4 && tmp5!=tmp6) return false;
            }
        }
        
        //handle the case where one string is bigger than the other and they are matching until now with 0 edits
        if(abs(m-n)>0) return true;
        else 
        //handle the case they have matched with one edit
        return (edits==1);
    }
};