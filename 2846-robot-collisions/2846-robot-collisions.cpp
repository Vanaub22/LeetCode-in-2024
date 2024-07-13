class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> idx,ans;
        for(int i=0;i<n;i++) idx.push_back(i);
        sort(idx.begin(),idx.end(),[&](int a, int b) {
            return positions[a]<positions[b];
        });
        stack<int> stk;
        for(int i:idx) {
            if(directions[i]=='R') stk.push(i);
            else while(!stk.empty() && healths[i]) {
                int j=stk.top();
                if(healths[i]<healths[j]) healths[j]--,healths[i]=0;
                else if(healths[i]>healths[j]) healths[i]--,healths[j]=0,stk.pop();
                else healths[i]=0,healths[j]=0,stk.pop();
            }
        }
        for(int i=0;i<n;i++) if(healths[i]) ans.push_back(healths[i]);
        return ans;
    }
};