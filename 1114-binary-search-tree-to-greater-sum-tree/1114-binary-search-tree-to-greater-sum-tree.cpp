/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, vector<TreeNode*>& inorder, int& total) {
        if(!root) return;
        traverse(root->left,inorder,total);
        inorder.push_back(root); // Pushing in actual node references
        total+=root->val;
        traverse(root->right,inorder,total);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root->left && !root->right) return root;
        vector<TreeNode*> traversal;
        int total=0,curr=0;
        traverse(root,traversal,total);
        // Progressing in ascending order, subtracting prefix sum from each node value
        for(auto node:traversal) {
            int temp=node->val;
            node->val=total-curr;
            curr+=temp;
        }
        return root;
    }
};