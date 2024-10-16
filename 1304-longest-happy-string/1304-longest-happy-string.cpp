class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        string res="";
        while(!pq.empty()) {
            auto [x1,c1]=pq.top();
            pq.pop();
            int n=res.size();
            if(n>=2 && res[n-1]==c1 && res[n-2]==c1) {
                if(pq.empty()) break;
                auto [x2,c2]=pq.top();
                pq.pop();
                res+=c2;
                x2--;
                if(x2) pq.push({x2,c2});
                pq.push({x1,c1});
            }
            else {
                res+=c1;
                x1--;
                if(x1) pq.push({x1,c1});
            }
        }
        return res;
    }
};