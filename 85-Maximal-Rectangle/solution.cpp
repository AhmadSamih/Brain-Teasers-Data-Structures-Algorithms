class Solution {
public:

int largestRectangleArea(vector<int>& hist) {
    int n = hist.size();
    stack<int> s;
 
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar
 
    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}
    
int maximalRectangle(vector<vector<char>>& matrix) {
    int x = matrix.size(); if(!x) return 0;
    int y = matrix[0].size();
    
    int max_rec = 0;
    vector<int>acc(y, 0);
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            acc[j] = (matrix[i][j] == '1') ? acc[j]+1 : 0;
        }
        max_rec = max(largestRectangleArea(acc), max_rec);
    }
    return max_rec;
}


};