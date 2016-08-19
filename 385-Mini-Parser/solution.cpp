/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.size() == 0)
            return NestedInteger();
        if(s[0] != '[')
            return NestedInteger(stoi(s));
            
        stack<NestedInteger>stk;
        //keep left,right ptrs to extract number
        int left = 0;
        for(int i =0; i<s.size(); i++){
            if(s[i] == '['){
                left = i+1;
                stk.push(NestedInteger());
            }else if(s[i] == ']'){
                //check if 
                if(left != i)
                    stk.top().add(NestedInteger(stoi(s.substr(left, i-left))));
                
                if(stk.size()>1){
                    auto tmp = stk.top();
                    stk.pop();
                    stk.top().add(tmp);
                }
                left = i+1;
            }else if(s[i] == ','){
                if(left != i)
                    stk.top().add(NestedInteger(stoi(s.substr(left, i-left))));
                left = i+1;
            }
        }
        
        return stk.top();
    }
};

