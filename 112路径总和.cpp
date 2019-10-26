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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return judge(root, sum);
    }
    bool judge(TreeNode* root, int sum){
         if(root == NULL){
            if(sum != 0)
                return false;
            return true;
        }
        return judge(root->left, sum - root->val) || judge(root->right, sum - root->val);
    }
};

/*
  []
  0
*/