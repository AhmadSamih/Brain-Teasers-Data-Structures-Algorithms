class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0)
        return nums.size();

    vector<int>::iterator m = nums.begin();  
    for (int& val : nums) {
        auto it = lower_bound(nums.begin(), m, val);
        *it = val;
        m = m + (it == m);
    }

    return m - nums.begin();
}
};

//This is quite different from the 2D max increasing sequence. Beucase that one is consequtive. 