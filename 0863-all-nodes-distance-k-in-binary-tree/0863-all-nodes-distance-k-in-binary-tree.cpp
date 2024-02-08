/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // Helper fn. to simply map all nodes to their parent nodes
    void markParents(TreeNode* root, auto& parentOf) {
        queue<TreeNode*> q;
        q.push(root);
        parentOf[root]=nullptr;
        while(!q.empty()) {
            TreeNode* node=q.front();
            q.pop();
            if(node->left) {
                parentOf[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                parentOf[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentOf;
        markParents(root,parentOf);
        vector<int> answer;
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        int distance=0;
        q.push(target);
        visited[target]=true;
        // Moving radially outwards in level-order fashion from the target node
        while(!q.empty()) {
            int n=q.size();
            if(distance==k) break;
            distance++;
            for(int i=1;i<=n;i++) {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentOf[node] && !visited[parentOf[node]]) {
                    q.push(parentOf[node]);
                    visited[parentOf[node]]=true;
                }
            }
        }
        while(!q.empty()) {
            answer.push_back(q.front()->val);
            q.pop();
        }
        return answer;
    }
};