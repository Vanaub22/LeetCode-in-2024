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
    int longestUnivaluePath(TreeNode* root) {
        int longestPath=0;
        findPath(root,-1,longestPath);
        return longestPath;
    }
    int findPath(TreeNode* root, int parent, int& lp) {
        if(!root) return 0;
        int left_cnt=findPath(root->left,root->val,lp),right_cnt=findPath(root->right,root->val,lp);
        lp=max(lp,left_cnt+right_cnt);
        return root->val==parent?max(left_cnt,right_cnt)+1:0;
    }
};