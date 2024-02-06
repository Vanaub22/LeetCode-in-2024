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
    // Using BFS
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool past=false; // To denote if the traversal has already seen an empty space
        while(!q.empty()) {
            TreeNode* node=q.front();
            q.pop();
            if(!node) past=true;
            else {
                if(past) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};