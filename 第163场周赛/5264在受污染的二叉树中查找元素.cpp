/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    map<int,bool>ret;
    void dfs(TreeNode* root,int val){
        if(!root) return ;
        ret[val] = true;
        dfs(root->left,2*val + 1);
        dfs(root->right,2*val + 2);
    }
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
        return ret[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */


/**
这种构造一个类的题目还是不知道  到底要干什么  （很简单的题）
*/