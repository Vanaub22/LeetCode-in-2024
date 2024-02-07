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
    // Helper fn. to convert the string representation to its binary equivalent value
    int binEq(auto& s) {
        int n=s.size(),val=0;
        for(int i=0;i<n;i++) val+=(s[i]-'0')<<(n-i-1);
        return val;
    }
    // Helper fn. to simply perform DFS and explore all root-to-leaf paths
    void dfs(auto root, string& s, int& res) {
        if(!root) return;
        s+=to_string(root->val);
        if(!root->left && !root->right) {
            res+=binEq(s);
            s.pop_back();
            return;
        }
        dfs(root->left,s,res);
        dfs(root->right,s,res);
        s.pop_back();
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        string s;
        int res=0;
        dfs(root,s,res);
        return res;
    }
};