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
    void deleteTargetLeaves(TreeNode*& root, int target, bool& foundTarget){
        foundTarget=false;
        if(!root) return;
        deleteTargetLeaves(root->left,target,foundTarget);
        deleteTargetLeaves(root->right,target,foundTarget);
        if(root && !root->left && !root->right && root->val==target){
            foundTarget=true;
            root=nullptr;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool foundTarget=true;
        while(foundTarget) deleteTargetLeaves(root,target,foundTarget);
        return root;
    }
};