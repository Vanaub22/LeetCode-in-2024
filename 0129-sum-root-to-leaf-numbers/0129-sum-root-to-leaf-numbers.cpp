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
    void sumToRoot(TreeNode* root, int x, int& s) {
        if(!root) return;
        x=x*10+root->val;
        if(!root->left && !root->right) s+=x;
        sumToRoot(root->left,x,s);
        sumToRoot(root->right,x,s);
    }
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        sumToRoot(root,0,res);
        return res;
    }
};