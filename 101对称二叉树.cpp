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
    bool isSymmetric(TreeNode* root) {
        TreeNode* nrt = build(root);
        return judge(root, nrt);
    }
    
    TreeNode* build(TreeNode* rt){
        if(!rt)
            return NULL;
        TreeNode* nrt = new TreeNode(rt->val);
       // cout<<nrt->val<<endl;
        nrt->left = build(rt->right);
        nrt->right = build(rt->left);
        return nrt;
    }
    
    bool judge(TreeNode* a, TreeNode* b){
        if((a && !b) || (!a && b))
            return false;
        if(!a || !b)
            return true;
        if(a->val != b->val)
            return false;
        return judge(a ? a->left : NULL, b ? b->left : NULL) && 
            judge(a ? a->right : NULL, b ? b->right : NULL);
    }
};

/**
    1.先把树翻转   得到一哥TreeNode *nroot
        看这两个树  是不是一样的
    2.
*/