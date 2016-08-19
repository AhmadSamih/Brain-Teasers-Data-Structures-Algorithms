#include <iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<string.h>
#include <unordered_set>
#include<set>
using namespace std;

struct Rectangle{
    int start_x;
    int end_x;
    int start_y;
    int end_y;
    Rectangle(int s_x, int e_x, int s_y, int e_y) : start_x(s_x), end_x(e_x), start_y(s_y), end_y(e_y) {}
   };

struct event{
  bool start_or_end;
  int coor;
  int rect_idx;
  event(int s_or_e, int _coor, int idx):start_or_end(s_or_e), coor(_coor), rect_idx(idx) {}
};
 
class Solution{
  public:
  vector<vector<int>> intersection(vector<Rectangle> v){
    vector<event>evnt;
    vector<vector<int>> res;
    for(uint32_t i=0; i<v.size(); i++){
      evnt.emplace_back(1,v[i].start_x,i);
      evnt.emplace_back(0,v[i].end_x,i);
    }
    sort(evnt.begin(), evnt.end(), [](event &a, event &b){return a.coor < b.coor;});
    
    set<int>actv_rects;
    for(uint32_t i=0; i<evnt.size();i++){
      if(evnt[i].start_or_end){
        for(auto itr = actv_rects.begin(); itr!= actv_rects.end(); itr++){
          int idx1 = evnt[i].rect_idx;
          int idx2 = *itr;
          if(!(v[idx1].end_y < v[idx2].start_y || v[idx2].end_y < v[idx1].start_y)){
            res.push_back({*itr, evnt[i].rect_idx });
          }
        }
        actv_rects.insert(evnt[i].rect_idx);
      }else{
        actv_rects.erase(evnt[i].rect_idx);
      }
    }
    
    return res;
  } 
};

int main() {
 
 Solution S;
   
  vector<Rectangle>v = {{0,100,0,100},{1,10,10,20},{11,25,22,35},{17,19,1,99},{9,70,3,15}};
  vector<vector<int>> res = S.intersection(v); 
  for(auto &out:res)
    cout<<"(" << out[0] <<"," << out[1]<< ")" << endl;
  return 0;
}

