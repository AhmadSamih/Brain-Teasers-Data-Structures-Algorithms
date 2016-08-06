class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        return bs(x, 1, x);
    }
    
    int bs(int x, int left, int right){
        while(left<right){
            int mid = left + (right-left)/2;
            if(mid>x/mid){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left-1;
    }
};