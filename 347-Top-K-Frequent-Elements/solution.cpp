class Solution {
public:

    struct heapNode{
      heapNode(int _value, int _freq):value(_value),freq(_freq){}
      int value;
      int freq;
    };
    
    struct greatThan
    {
      bool operator()(const heapNode *l, const heapNode *r) const
      {
        return l->freq > r->freq;
      }
    };
    
    priority_queue<heapNode*, vector<heapNode*>, greatThan> maxH;
    unordered_map<int,int>cache;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;
        for(int i = 0; i< nums.size(); i++){
            cache[nums[i]]++;
        }    
       
        for(auto itr = cache.begin(); itr!=cache.end(); itr++){
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
    return res;
    }
};