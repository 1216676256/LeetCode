/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int>ans;
    vector<int> postorder(Node* root) {
        find(root);
        return ans;
    }
    
    void find(Node* root){
        if(root == NULL){
            return ;
        }
        int len = root->children.size();
        for(int i = 0; i < len; i++){
            find(root->children[i]);
        }
        ans.push_back(root -> val);
    }
};