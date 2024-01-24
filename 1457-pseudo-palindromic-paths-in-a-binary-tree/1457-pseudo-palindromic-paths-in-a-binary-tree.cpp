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
    int pseudoPalindromicPaths (TreeNode* root) {
        int freq[10];
        memset(freq,0,sizeof(freq));
        int cnt=0;
        countValidPaths(root,freq,cnt);
        return cnt;
    }
    void countValidPaths(TreeNode* root, int freq[], int& cnt) {
        if(!root) return;
        freq[root->val]++;
        countValidPaths(root->left,freq,cnt);
        countValidPaths(root->right,freq,cnt);
        // Checking will be done when we are at a leaf node
        // This ensures that we can remove the node from freq[] because that subtree is visited
        if(!root->left && !root->right) {
            int odd_cnt=0;
            for(int i=0;i<10;i++) if(freq[i]%2!=0) odd_cnt++;
            if(odd_cnt<=1) cnt++;
        }
        freq[root->val]--;
    }

};