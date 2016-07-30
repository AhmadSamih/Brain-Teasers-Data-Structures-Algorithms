class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int start = s.find_first_not_of(' ');
        if(start == string::npos) start = 0;
            
        int end = s.find_first_of(' ', start);
        if(end == string::npos) end = s.size();

        return end-start;
    }
};