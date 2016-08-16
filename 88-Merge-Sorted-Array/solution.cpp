class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(!n) return;
        vector<int> tmp(m+n);
        
        int i = 0, j = 0;
        for(int k = 0; k< m+n; k++){
            if((i<m) && (nums1[i] < nums2[j] || j>=n)){
                tmp[k] = nums1[i];
                i++;
            }else{
                tmp[k] = nums2[j];
                j++;
            }
        }
        nums1 = tmp;
    }
};