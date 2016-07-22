class Solution {
public:
void reverseWords(string &s) {
  reverse(s.begin(), s.end());
  uint32_t start=0; uint32_t end =0;
  while(end<s.size()){
    while(end<s.size() && s[end]!=' ')end++;
    reverse(s.begin()+start, s.begin()+end);
    start= ++end;
  }
}
};