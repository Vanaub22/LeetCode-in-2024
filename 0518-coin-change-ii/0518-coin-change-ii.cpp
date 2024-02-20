class Solution {
private:
    int solve(int i, int amt, auto& coins, vector<vector<int>>& memo) {
        if(i>=coins.size() || amt<0) return 0;
        if(amt==0) return 1;
        if(memo[i][amt]!=-1) return memo[i][amt];
        int combinations=0;
        for(int j=i;j<coins.size();j++) combinations+=solve(j,amt-coins[j],coins,memo);
        return memo[i][amt]=combinations;
    }
public:
    int change(int amt, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(),vector<int>(amt+1,-1));
        return solve(0,amt,coins,memo);
    }
};