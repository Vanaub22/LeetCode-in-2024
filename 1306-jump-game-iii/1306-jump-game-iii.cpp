class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(!arr[start]) return true;
        int n=arr.size();
        // Performing BFS to determine if reaching a value 0 is possible or not
        queue<int> q;
        bool visited[n];
        memset(visited,false,sizeof(visited));
        visited[start]=true;
        q.push(start);
        while(!q.empty()) {
            int curr=q.front();
            q.pop();
            if(curr+arr[curr]>=0 && curr+arr[curr]<n && !visited[curr+arr[curr]]) {
                if(!arr[curr+arr[curr]]) return true;
                visited[curr+arr[curr]]=true;
                q.push(curr+arr[curr]);
            }
            if(curr-arr[curr]>=0 && curr-arr[curr]<n && !visited[curr-arr[curr]]) {
                if(!arr[curr-arr[curr]]) return true;
                visited[curr-arr[curr]]=true;
                q.push(curr-arr[curr]);
            }
        }
        return false;
    }
};