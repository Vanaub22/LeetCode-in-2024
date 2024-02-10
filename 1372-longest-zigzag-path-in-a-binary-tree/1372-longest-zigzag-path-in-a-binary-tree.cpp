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
    void moveZigZag(TreeNode* root, bool moveLeft, int steps, int& res) {
        if(!root) return;
        res=max(res,steps);
        // Either following this zigzag path (if possible) or starting a new one from this node
        if(moveLeft) {
            moveZigZag(root->left,!moveLeft,steps+1,res);
            moveZigZag(root->right,moveLeft,1,res);
        }
        else {
            moveZigZag(root->right,!moveLeft,steps+1,res);
            moveZigZag(root->left,moveLeft,1,res);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int res=0;
        moveZigZag(root,true,0,res);
        moveZigZag(root,false,0,res);
        return res;
    }
};