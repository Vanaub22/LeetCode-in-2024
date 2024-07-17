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
    void solve(TreeNode* parent, TreeNode* curr, auto& rootForest, auto& deleteSet, bool isLeft) {
        if(!curr) return;
        solve(curr,curr->left,rootForest,deleteSet,true);
        solve(curr,curr->right,rootForest,deleteSet,false);
        if(deleteSet.find(curr->val)!=deleteSet.end()) {
            if(rootForest.find(curr->val)!=rootForest.end()) rootForest.erase(curr->val);
            if(parent) {
                if(isLeft) parent->left=nullptr;
                else parent->right=nullptr;
            }
            if(curr->left) rootForest[curr->left->val]=curr->left;
            if(curr->right) rootForest[curr->right->val]=curr->right;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_map<int,TreeNode*> rootForest;
        unordered_set<int> deleteSet(to_delete.begin(),to_delete.end());
        rootForest[root->val]=root;
        solve(nullptr,root,rootForest,deleteSet,true);
        for(auto& [_,root]:rootForest) ans.emplace_back(root);
        return ans;
    }
};