class Solution {
private:
    int solve(int i, int amount, auto& coins, vector<vector<int>>& memo) {
        if(i>=coins.size() || amount<0) return 0;
        if(amount==0) return 1;
        if(memo[i][amount]!=-1) return memo[i][amount];
        int combinations=0;
        for(int j=i;j<coins.size();j++) combinations+=solve(j,amount-coins[j],coins,memo);
        return memo[i][amount]=combinations;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins,memo);
    }
};