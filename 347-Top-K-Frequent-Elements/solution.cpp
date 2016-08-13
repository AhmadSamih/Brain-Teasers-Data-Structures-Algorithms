class Solution {
public:

    struct greatThan{
      bool operator()(pair<int,int>a, pair<int,int>b){
        return a.second < b.second;
      }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int>cache;

        for(auto &num:nums)
            cache[num]++;
    
        priority_queue<pair<int,int>, vector<pair<int,int>>, greatThan> maxH(cache.begin(), cache.end());

        for(int i=0; i<k;i++){
            res.push_back(maxH.top().first);
            maxH.pop();
        }
/*        for(auto itr = cache.begin(); itr!=cache.end(); itr++){
            heapNode * x = new heapNode(itr->first, itr->second);
            maxH.push(x);
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        
    //traverse the heap and push it back to vector
    while(!maxH.empty()){
        heapNode * x = maxH.top();
        res.insert(res.begin(), x->value);
        maxH.pop();
    }
    */
        return res;
    }
};