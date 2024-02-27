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
private:
    int getHeight(TreeNode* root, int& diameter) {
        if(!root) return 0;
        int leftHeight=getHeight(root->left,diameter),rightHeight=getHeight(root->right,diameter);
        diameter=max(diameter,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter=0;
        getHeight(root,diameter);
        return diameter;
    }
};