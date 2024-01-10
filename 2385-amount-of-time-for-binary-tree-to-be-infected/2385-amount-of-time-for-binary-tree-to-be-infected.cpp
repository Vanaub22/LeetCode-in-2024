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
 #define MAX 100001
class Solution {
public:
    // Using DFS to convert Tree to undirected graph
    void makeGraph(TreeNode* root, unordered_map<int,vector<int>>& adjList) {
        if(!root) return;
        if(root->left) {
            adjList[root->val].emplace_back(root->left->val);
            adjList[root->left->val].emplace_back(root->val);
        }
        if(root->right) {
            adjList[root->val].emplace_back(root->right->val);
            adjList[root->right->val].emplace_back(root->val);
        }
        makeGraph(root->left,adjList);
        makeGraph(root->right,adjList);
    }
    // Performing BFS on undirected graph to find the time taken to infect the entire tree
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adjList;
        makeGraph(root,adjList);
        queue<int> q;
        bool visited[MAX];
        memset(visited,false,sizeof(visited));
        q.push(start);
        visited[start]=true;
        int t=-1; // 1 minute is wasted in visiting starting node (already infected)
        while(!q.empty()) {
            t++;
            int n=q.size();
            for(int i=1;i<=n;i++) {
                int node=q.front();
                q.pop();
                for(int neighbour:adjList[node]) {
                    if(!visited[neighbour]) {
                        q.push(neighbour);
                        visited[neighbour]=true;
                    }
                }
            }
        }
        return t;
    }
};