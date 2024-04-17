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
    void build(TreeNode* root, string s, string& res) {
        if(!root) return;
        s+='a'+root->val;
        if(!root->left && !root->right) {
            string r=s;
            reverse(r.begin(),r.end());
            if(r<res) res=r;
        }
        build(root->left,s,res);
        build(root->right,s,res);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string res="~";
        build(root,"",res);
        return res;
    }
};