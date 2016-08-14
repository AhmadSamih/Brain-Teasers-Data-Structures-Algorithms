class Solution {
public:
    int hIndex(vector<int>& citations) {
        //Explanation, max H-Index is number of papers
        int n = citations.size();

        //if the least cited paper has more than n citations, then H is n, otherwise, we try the next paper and compare it to n-1
        int i = 0;
        for(;i<n; i++){
            if(citations[i]>=(n-i))
                return n-i;
        }
        return (n-i);
        
        //to optimize this, we can do it in a binary search approach
        int left = 0;
        int right = n-1;
        while(left <=  right){
            if(left == right) break;
            int mid = (left+right)/2;
            if(citations[mid]>= (n-mid)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return n-left;
    }
};