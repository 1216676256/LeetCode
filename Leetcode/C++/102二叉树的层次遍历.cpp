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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return ans;
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* root){
        queue<TreeNode*>q;
        queue<TreeNode*>tmp;
        q.push(root);
        int flag = 1;
        while(flag){
             vector<int>res;
            flag = 0;
             while(!q.empty()){
                
                TreeNode* nx = q.front();
                q.pop();
                res.push_back(nx->val);
                if(nx->left != NULL){
                    tmp.push(nx->left);
                    flag = 1;
                }
                if(nx->right != NULL){
                    tmp.push(nx->right);
                    flag = 1;
                }
            }
            q = tmp;
            //cout<<"AAA"<<q.size()<<"  "<<flag<<endl;
            //tmp.clear();没有现成的清空函数
            queue<TreeNode*>().swap(tmp);
            ans.push_back(res);
        }
    }
};