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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) return new TreeNode(val,root,nullptr); // Changing the root
        queue<TreeNode*> q;
        q.push(root);
        int d=1; // Storing the current depth
        // Descending to required depth by level-order traversal
        while(!q.empty() && depth>2) {
            int n=q.size();
            for(int i=1;i<=n;i++) {
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            d++;
            if(d==depth-1) break; // Reached the required depth for insertion
        }
        while(!q.empty()) {
            auto x=q.front(),newLeft=new TreeNode(val,x->left,nullptr),newRight=new TreeNode(val,nullptr,x->right);
            x->left=newLeft,x->right=newRight;
            q.pop();
        }
        return root;
    }
};