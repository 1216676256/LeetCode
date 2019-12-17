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
        //cout<<sum<<endl;
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val){
                return true;
            }
            return false;
        }
        if(root->left != NULL){
            if(judge(root->left, sum - root->val))
                return true;
        }
        if(root->right != NULL){
            if(judge(root->right, sum - root->val))
                return true;
        }
        return false;
    }
};

/*
  []
  0
*/