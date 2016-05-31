/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:

    stack<TreeNode *> stk;

    BSTIterator(TreeNode *root) {
        while(root){
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto ptr = stk.top();
        int val = ptr->val;
        stk.pop();
        
        //move on to successor
        ptr = ptr -> right;
        while(ptr){
            stk.push(ptr);
            ptr = ptr->left;
        }
        
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */