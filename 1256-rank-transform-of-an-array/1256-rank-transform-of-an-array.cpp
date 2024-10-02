class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        unordered_map<int,int> ranking;
        vector<int> tmp(arr.begin(),arr.end()),ans;
        sort(arr.begin(),arr.end());
        ranking[arr[0]]=1;
        int n=arr.size(),rank=1,prev=arr[0];
        for(int i=1;i<n;i++) {
            if(prev!=arr[i]) {
                ranking[arr[i]]=++rank;
                prev=arr[i];
            }
            else ranking[arr[i]]=rank;
        }
        for(int i:tmp) ans.emplace_back(ranking[i]);
        return ans;
    }
};