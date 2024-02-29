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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int lvl=0;
        q.push(root);
        while(!q.empty()) {
            int prev,n=q.size();
            for(int i=0;i<n;i++) {
                auto node=q.front();
                q.pop();
                if(lvl%2) {
                    if(node->val%2) return false;
                    if(i && prev<=node->val) return false;
                }
                else {
                    if(node->val%2==0) return false;
                    if(i && prev>=node->val) return false;
                }
                prev=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lvl++;
        }
        return true;
    }
};