class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size(),pos=1;
        vector<pair<int,int>> ds;
        vector<string> ans(n);
        for(int i=0;i<n;i++) ds.push_back(make_pair(score[i],i));
        sort(ds.begin(),ds.end(),greater<pair<int,int>>());
        while(true) {
            int idx=ds[pos-1].second;
            if(pos==1) ans[idx]="Gold Medal";
            else if(pos==2) ans[idx]="Silver Medal";
            else if(pos==3) ans[idx]="Bronze Medal";
            else ans[idx]=to_string(pos);
            if(pos==n) break;
            pos++;
        }
        return ans;
    }
};