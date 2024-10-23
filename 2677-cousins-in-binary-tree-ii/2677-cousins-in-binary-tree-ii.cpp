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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;
        bfs_compute(root,levelSum);
        dfs_fill(root,levelSum,0);
        return root;
    }
    void dfs_fill(TreeNode* root, vector<int>& ls, int d) {
        if(!root) return;
        if(d==0) root->val=0; // The root of the Tree does not have any cousins
        int deduction=0;
        if(root->left) deduction+=root->left->val;
        if(root->right) deduction+=root->right->val;
        if(root->left) root->left->val=ls[d+1]-deduction;
        if(root->right) root->right->val=ls[d+1]-deduction;
        dfs_fill(root->left,ls,d+1);
        dfs_fill(root->right,ls,d+1);
    }
    void bfs_compute(TreeNode* root, vector<int>& levelSum) {
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty()) {
            int sum=0,n=q.size();
            for(int i=0;i<n;i++) {
                TreeNode* x=q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                sum+=x->val;
            }
            levelSum.emplace_back(sum);
            depth++;            
        }
    }
};