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
    }
};