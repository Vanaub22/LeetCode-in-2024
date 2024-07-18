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
    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        // Fn. to return vector distances to all the leaf nodes from current node
        function<vector<int>(TreeNode*)> solve=[&ans,distance,&solve](TreeNode* root)->vector<int> {
            if(!root) return {0};
            else if(!root->left && !root->right) return {1};
            vector<int> ld=solve(root->left),rd=solve(root->right);
            for(int i:ld) for(int j:rd) if(i && j && i+j<=distance) ans++;
            vector<int> dist;
            for(int i:ld) if(i && i+1<distance) dist.emplace_back(i+1);
            for(int i:rd) if(i && i+1<distance) dist.emplace_back(i+1);
            return dist;
        };
        solve(root);
        return ans;
    }
};