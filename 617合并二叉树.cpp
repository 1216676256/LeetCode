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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return dfs(t1, t2);
    }
    
    TreeNode* dfs(TreeNode* rt1, TreeNode* rt2){
        if(!rt1 && !rt2)
            return NULL;
        if(rt1 && rt2){
            rt1->val += rt2->val;
        }
        if(!rt1 && rt2){
            rt1 = new TreeNode(rt2->val);
        }
        rt1->left = dfs(rt1->left, !rt2 ? NULL : rt2->left);  //这里是一个细节
        rt1->right = dfs(rt1->right, !rt2 ? NULL : rt2->right);
        return rt1;
    }
};