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
    vector<int>tmp;
    int ind;
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(tmp.begin(), tmp.end());
        ind = 0;
        recover(root);
    }
    
    void dfs(TreeNode* rt){
        if(!rt)
            return ;
        tmp.push_back(rt->val);
        dfs(rt->left);
        dfs(rt->right);
    }
    
    void recover(TreeNode * rt){
        if(!rt)
            return ;
        recover(rt->left);
        rt->val = tmp[ind++];
        recover(rt->right);
    }
};

/**
    1. 先递归复原子树    再来操作本身节点
    过一下示例2   事情并不是想的那么简单....
    
    2.  可以先获得该树的所有元素，排完序
    根据二叉搜索树的特点，左边小，右边大
    中序遍历二叉树，就可以获得  递增的（下标）   再把相应的元素填进去就行了    
    空间复杂度O（n）  时间复杂度 O(n)
*/