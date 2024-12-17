class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> f;
        for(char c:s) f[c]++;
        priority_queue<pair<char,int>> pq;
        for(auto& [c,i]:f) pq.push({c,i});
        string ans="";
        while(!pq.empty()) {
            auto [c1,i]=pq.top();
            pq.pop();
            int add=min(i,repeatLimit);
            ans+=string(add,c1);
            i-=add;
            if(i>0 && !pq.empty()) {
                auto [c2,j]=pq.top();
                pq.pop();
                ans+=c2,j--;
                if(j>0) pq.push({c2,j});
                pq.push({c1,i});
            }
        }
        return ans;
    }
};