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
    int mx = 1e9+7;
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root ->left == NULL && root->right == NULL)
            return 1;
        return min(root->left != NULL ? minDepth(root->left) : mx, root->right != NULL ? minDepth(root->right) :mx) +1;
    }
};