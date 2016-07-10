class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        vector<int>column(height.size(), 0);
        
        for(int i=1 ;i<height.size(); i++){
            while(i<height.size()-1 && height[i]<height[i-1])i++;

            int left_wall_idx = 0;
            int left_wall = 0;
            int right_wall = height[i];
            for(int j=i-1; j>=0; j--){
                if(left_wall>right_wall) break;
                if(height[j]>left_wall){
                    left_wall_idx = j;
                    left_wall = height[j];
                }
            }
            int prac = min (height[left_wall_idx], right_wall);
            for(int j=i-1; j>left_wall_idx; j--){ //walk between the two walls
                column[j] = prac - height[j];
            }
        }
        
        int sum = 0;
        for(auto x:column)sum+=x;

        return sum;
    }
};