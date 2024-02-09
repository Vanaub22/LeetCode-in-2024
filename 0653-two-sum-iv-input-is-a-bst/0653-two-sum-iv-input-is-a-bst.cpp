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
    void dfs(TreeNode* root, vector<int>& x) {
        if(!root) return;
        x.push_back(root->val);
        dfs(root->left,x);
        dfs(root->right,x);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> x;
        dfs(root,x);
        int n=x.size();
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j && x[i]+x[j]==k) return true;
        return false;
    }
};