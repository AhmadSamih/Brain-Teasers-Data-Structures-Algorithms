class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int,int>>R(height.size(), pair<int,int>(0,0));
        vector<pair<int,int>>L(height.size(), pair<int,int>(0,0));
        
        for(int i=height.size()-2; i>=0; i--){
            if(height[i+1] > R[i+1].first)
                R[i].first = height[i+1], R[i].second = i+1;
            else
                R[i].first = R[i+1].first, R[i].second = R[i+1].second;    
        }

        for(int i=1; i<height.size(); i++){
            if(height[i-1] > L[i-1].first)
                L[i].first = height[i-1], L[i].second = i-1;
            else
                L[i].first = L[i-1].first, L[i].second = L[i-1].second;    
        }
        

        int sum = 0;
        for(int i=0; i<height.size();i++){
            int m = min(R[i].first, L[i].first) - height[i];
            if(m>0) sum +=m;
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