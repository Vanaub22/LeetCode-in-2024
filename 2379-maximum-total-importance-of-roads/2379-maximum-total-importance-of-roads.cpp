#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ll maxImportance=0,importance=n;
        unordered_map<int,ll> freq;
        for(auto it:roads) freq[it[0]]++,freq[it[1]]++;           
        vector<pair<int,ll>> visits(freq.begin(),freq.end());
        sort(visits.begin(),visits.end(),[&](auto& a, auto& b) {
            return a.second>b.second;
        });
        for(auto& vis:visits) maxImportance+=vis.second*importance--;
        return maxImportance;
    }
};