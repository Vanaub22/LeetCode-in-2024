class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(!arr[start]) return true;
        int n=arr.size();
        // Converting into an adjacency list
        vector<int> adj[n];
        for(int i=0;i<n;i++) {
            if(i-arr[i]>=0 && i-arr[i]<=n-1) adj[i].push_back(i-arr[i]);
            if(i+arr[i]>=0 && i+arr[i]<=n-1) adj[i].push_back(i+arr[i]);
        }
        // Performing BFS to determine if reaching a value 0 is possible or not
        queue<int> q;
        bool visited[n];
        memset(visited,false,sizeof(visited));
        visited[start]=true;
        q.push(start);
        while(!q.empty()) {
            int curr=q.front();
            q.pop();
            for(int i:adj[curr]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i]=true;
                    if(!arr[i]) return true;
                }
            }
        }
        return false;
    }
};