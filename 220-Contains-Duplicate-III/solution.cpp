class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
         if(nums.size() < 2) return false;
         vector<pair<int,int>> v;
         for(int i = 0; i < nums.size(); i++)
             v.push_back(make_pair(nums[i],i));

         sort(v.begin(),v.end(),[](pair<int,int>&a, pair<int,int>&b){return a.first < b.first;});
         
         for(int i = 0; i < nums.size(); i++){
             int j = i + 1;
             while(j < v.size()){
                 if(abs((long)v[j].first-(long)v[i].first) > t)  break;
                 else if(abs(v[i].second-v[j].second) <= k){
                     return true;
                 }
                 else
                     j++;
             }
         }
         return false;
    }
};