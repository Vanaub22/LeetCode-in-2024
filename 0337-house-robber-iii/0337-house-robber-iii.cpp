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
    int solve(TreeNode* root, unordered_map<TreeNode*,int>& memo) {
        if(!root) return 0;
        if(memo.find(root)!=memo.end()) return memo[root];
        int robbed=root->val;
        if(root->left) robbed+=solve(root->left->left,memo)+solve(root->left->right,memo);
        if(root->right) robbed+=solve(root->right->left,memo)+solve(root->right->right,memo);
        return memo[root]=max(robbed,solve(root->left,memo)+solve(root->right,memo));
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> memo; // For memoization
        return solve(root,memo);
    }
};