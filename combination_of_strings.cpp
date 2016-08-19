void recur(string s, int si, string p, int pi, string tmp){
  if(tmp.size() == (s.size()+p.size())){
    cout<<tmp<<endl;
    return;
  }

  if(si < s.size())
    recur(s, si+1, p, pi, tmp+s[si]);
  
  if(pi < p.size())
    recur(s, si, p, pi+1, tmp+p[pi]);
  
  return;
}


int main() {

  string w1 = "AB";
  string w2 = "CD";
  
  recur(w1,0, w2,0, "");
  
  return 0;
}
