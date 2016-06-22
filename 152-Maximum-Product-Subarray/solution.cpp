class Solution {
public:
    int maxProduct(vector<int>& A) {
    if (A.size() == 0) {
        return 0;
    }

    int maxherepre = A[0];
    int minherepre = A[0];
    int maxsofar = A[0];
    int maxhere, minhere;

    for (int i = 1; i < A.size(); i++) {
        maxhere = max(max(maxherepre * A[i], minherepre * A[i]), A[i]);
        minhere = min(min(maxherepre * A[i], minherepre * A[i]), A[i]);
        maxsofar = max(maxhere, maxsofar);
        maxherepre = maxhere;
        minherepre = minhere;
    }
    return maxsofar;

    }
};