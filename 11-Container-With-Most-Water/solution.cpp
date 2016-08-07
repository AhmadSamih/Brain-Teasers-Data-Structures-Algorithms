class Solution {
public:
    int maxArea(vector<int>& height) {
 
        int start = 0;
        int end = height.size()-1;
        
        int m = 0;
        while(start<end){
            m = max(m, (end-start)*min(height[start], height[end]));
            if(height[start] < height[end]) start++;
            else end--;
        }
        return m;
    }
};