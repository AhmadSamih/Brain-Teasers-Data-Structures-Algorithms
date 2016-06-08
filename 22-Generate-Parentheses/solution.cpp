class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	if (n == 0) return res;
        string tmp2 = "";
    	traverse(res, n, n, tmp2);
    	return res;
    }

    void traverse(vector<string> &res, int lefts, int rights, string tmp2){
        if(lefts == 0 && rights == 0) res.push_back(tmp2);
	    if(lefts < 0 || rights < lefts) return;
        if(lefts > 0) {
    		traverse(res, lefts-1, rights, tmp2+'(');
    	 }
        if(rights > 0) {
	    	traverse(res, lefts, rights-1, tmp2+')');
	    }
    }
};

