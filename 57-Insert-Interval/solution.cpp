/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(Interval& a, Interval& b){
         return a.start < b.start;
     }
     
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      vector<Interval> res;
      //intervals.insert(lower_bound(intervals.begin(), intervals.end(), comp),newInterval);
      int start = 0;
      int end = intervals.size()-1;
      int mid;
      while(start<=end && intervals.size()>0){
          mid = (start+end) / 2;
          if(intervals[mid].start > newInterval.start){
              end = mid-1;
          }else{
              start = mid+1;
          }
      }
      
      if(intervals.size() == 0)
        intervals.push_back(newInterval);
      else
        intervals.insert(intervals.begin()+start, newInterval);
      //sort(intervals.begin(), intervals.end(), comp);
      //sort intervals based on the start index
      
       res.push_back(intervals[0]);
       for(uint32_t i=1; i<intervals.size();i++){
         if(intervals[i].start <= res.back().end){
           res.back().end = max(res.back().end, intervals[i].end);
           //cout<<"{"<<res.back().id<<","<<intervals[i].id<<"}"<<endl;
         }else{
           res.push_back(intervals[i]);
         }
      }
      return res;
    }
};