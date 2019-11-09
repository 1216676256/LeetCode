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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>res;
        if(n<=0)
            return res;
        return generate(1,n);
    }
    
    vector<TreeNode*> generate(int L, int R){
        vector<TreeNode*> ans;
        if(L>R){
            ans.push_back(nullptr);
            return ans;
        }     
        for(int i = L; i <= R; i++){
            
            vector<TreeNode*>left = generate(L,i - 1);
            vector<TreeNode*>right = generate(i+1,R);
            for(auto l: left){
                for(auto r : right){
                    TreeNode* root =new TreeNode(i);//这里每次都要申请一下
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

/**
    没啥思路（有思路也实现不了...）试一试
    最终还是实现了     auto r：right  快速遍历集合 
    
*/