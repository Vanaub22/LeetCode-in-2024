class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        unordered_map<int,int> trust_won,trusting;
        for(auto& it:trust) trusting[it[0]]++,trust_won[it[1]]++;
        for(auto& it:trust_won) if(it.second==n-1 && trusting[it.first]==0) return it.first;
        return -1;
    }
};