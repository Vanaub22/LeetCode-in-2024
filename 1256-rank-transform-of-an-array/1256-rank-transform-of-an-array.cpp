class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        unordered_map<int,int> ranking;
        vector<int> tmp(arr.begin(),arr.end()),ans;
        sort(tmp.begin(),tmp.end());
        ranking[tmp[0]]=1;
        int n=tmp.size(),rank=1,prev=tmp[0];
        for(int i=1;i<n;i++) {
            if(prev!=tmp[i]) {
                ranking[tmp[i]]=++rank;
                prev=tmp[i];
            }
            else ranking[tmp[i]]=rank;
        }
        for(int i:arr) ans.emplace_back(ranking[i]);
        return ans;
    }
};