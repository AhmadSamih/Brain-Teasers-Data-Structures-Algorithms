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
    // Corner case "123"
    if (s[0] != '[') {
      return NestedInteger(stoi(s));
    }

    uint32_t left = 1;
    stack<NestedInteger> stk;

    for(uint32_t i=0; i<s.size(); i++){
      char c = s[i];
      if (c == '[') {
        stk.push(NestedInteger());
        left = i + 1;
      } else if (c == ',' || c == ']') {
        if (left != i) {
          string tt = s.substr(left, i-left);
          stk.top().add(NestedInteger(stoi(tt)));
        }
        left = i + 1;
        if (c == ']') {
           if(stk.size()>1){//current level nested list has an outer nested list
                NestedInteger cur = stk.top();
                stk.pop();
                stk.top().add(cur);
            }
        }
      }
    }
    return stk.top();
}
};