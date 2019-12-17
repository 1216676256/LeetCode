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
    vector<vector<int>>ans;
    vector<int>path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return ans;
        dfs(root, sum);
        return ans;
    }
    
    void dfs(TreeNode* root, int need){
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(need == root->val){
                ans.push_back(path);
            }
            return ;
        }
        if(root->left != NULL){
            dfs(root->left, need - root->val);
            path.pop_back();
        }
       
       if(root->right != NULL){
            dfs(root->right, need - root->val);
            path.pop_back();
        }
        
        return ;
    }
};