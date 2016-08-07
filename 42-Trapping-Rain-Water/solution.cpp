class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>R(height.size(),0);
        vector<int>L(height.size(),0);
        
        for(int i=height.size()-2; i>=0; i--)
            R[i] = max(height[i+1],R[i+1]);
        for(int i=1; i<height.size(); i++)
            L[i] = max(height[i-1],L[i-1]);
            
        int sum = 0;
        for(int i=0; i<height.size();i++){
            sum += max(0, min(R[i], L[i]) - height[i]);
        }
        return sum;
        
 /*       if(height.empty()) return 0;
        vector<int>column(height.size(), 0);
        
        for(int i=1 ;i<height.size(); ++i){
            while(i<height.size()-1 && height[i]<height[i-1])++i;

            int left_wall = 0;
            int right_wall = height[i];
            int left_wall_idx = 0;
            for(int j=i-1; j>=0; --j){
                if(left_wall>right_wall) break;
                if(height[j]>left_wall){
                    left_wall = height[j];
                    left_wall_idx = j;
                }
            }
            int prac = min (left_wall, right_wall);
            for(int j=i-1; j>left_wall_idx; --j){ //walk between the two walls
                column[j] = prac - height[j];
            }
        }
        
        int sum = 0;
        for(auto &x:column)
            sum+=x;

        return sum;
 */
    }
};