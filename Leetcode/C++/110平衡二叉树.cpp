/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int flag = 1;
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        getDepth(root);
        return flag;
    }
    
    int getDepth(TreeNode* rt){
        if(flag == 0)
            return 0;
        if(rt == NULL)
            return 0;
        int L = getDepth(rt->left);
        int R = getDepth(rt->right);
        if(abs(L-R) >= 2)
            flag = 0;
        return max(L, R) + 1;
    }
};