/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    deque<pair<int,int>>nums;
    int max_depth;
    
    void DFS(vector<NestedInteger>&nestedList, int depth){
        max_depth = max(max_depth, depth);
        if(nestedList.size() == 0) return;
        for(int i=0; i<nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                nums.emplace_back(nestedList[i].getInteger(), depth);
            }else{
                DFS(nestedList[i].getList(), depth+1);
            }
        }
        
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        DFS(nestedList, 1);
        int sum = 0;
        while(!nums.empty()){
            sum += nums.front().first * (max_depth - nums.front().second+1);
            nums.pop_front();
        }
        return sum;
    }
};