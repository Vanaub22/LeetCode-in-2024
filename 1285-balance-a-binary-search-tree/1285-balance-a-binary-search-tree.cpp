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
    TreeNode* createTree(vector<int>& arr, int start, int end){
        if(start>end) return nullptr;
        int mid=start+(end-start)/2;
        TreeNode* balanced=new TreeNode(arr[mid],createTree(arr,start,mid-1),createTree(arr,mid+1,end));
        return balanced;
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return createTree(arr,0,arr.size()-1);
    }
};