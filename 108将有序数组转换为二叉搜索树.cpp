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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return buildBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* buildBST(vector<int>&v,int L, int R){
        if(L > R)
            return NULL;
        int mid = L + (R - L) / 2;
        TreeNode* rt = new TreeNode(v[mid]);
        rt->left = buildBST(v, L, mid - 1);
        rt->right = buildBST(v, mid + 1, R);
        return rt;
    }
};