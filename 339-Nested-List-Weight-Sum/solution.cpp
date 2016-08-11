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
/*    stack<std::vector<NestedInteger>::iterator> stk_b;
    stack<std::vector<NestedInteger>::iterator> stk_e;
    int depthSum(vector<NestedInteger>& nestedList) {
        if(nestedList.empty()) return 0;
        int sum = 0;
        stk_b.push(nestedList.begin());
        stk_e.push(nestedList.end());
        while(!stk_b.empty()){
            if(stk_b.top() == stk_e.top()){
                stk_b.pop();
                stk_e.pop();
            }else{
                auto itr = stk_b.top()++;
                if(itr->isInteger()){
                    sum+= itr->getInteger()*stk_b.size();
                }else{
                    stk_b.push(itr->getList().begin());
                    stk_e.push(itr->getList().end());
                }
            }
        }
        return sum;
    }
*/
    void dfs(vector<NestedInteger>& nestedList, int depth, int& sum){
        if(nestedList.empty()) return;
        for(int i=0; i<nestedList.size();i++){
            if(nestedList[i].isInteger()){
                sum += nestedList[i].getInteger()*depth;
            }else{
                dfs(nestedList[i].getList(), depth+1, sum);
            }
        }
    }
    
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0;
        dfs(nestedList, 1, sum);
        return sum;
    }
    
};