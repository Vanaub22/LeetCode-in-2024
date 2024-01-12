class Solution {
public:
    // Recursive solution using DFS gives TLE
    // Iterative solution with BFS passes
    vector<int> numsSameConsecDiff(int n, int k) {
        int llim=pow(10,n-1);
        vector<int> res;
        queue<int> q;
        for(int i=1;i<10;i++) q.push(i);
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            if(x>=llim) res.emplace_back(x);
            else {
                int ldig=x%10;
                if(ldig+k<=9) q.push(x*10+ldig+k);
                if(ldig-k>=0 && k!=0) q.push(x*10+ldig-k);
            }
        }
        return res;
    }
};