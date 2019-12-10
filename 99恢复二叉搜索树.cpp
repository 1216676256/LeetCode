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
    1. �ȵݹ鸴ԭ����    ������������ڵ�
    ��һ��ʾ��2   ���鲢���������ô��....
    
    2.  �����Ȼ�ø���������Ԫ�أ�������
    ���ݶ������������ص㣬���С���ұߴ�
    ����������������Ϳ��Ի��  �����ģ��±꣩   �ٰ���Ӧ��Ԫ�����ȥ������    
    �ռ临�Ӷ�O��n��  ʱ�临�Ӷ� O(n)
*/