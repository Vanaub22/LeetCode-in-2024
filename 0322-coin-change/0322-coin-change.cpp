class Solution {
private:
    int solve(int i, int amount, auto& coins, vector<vector<int>>& memo) {
        if(amount==0) return 0;
        if(i>=coins.size() || amount<0) return 1e5;
        if(memo[i][amount]!=-1) return memo[i][amount];
        int take=1+min(solve(i+1,amount-coins[i],coins,memo),solve(i,amount-coins[i],coins,memo));
        int not_take=solve(i+1,amount,coins,memo);
        return memo[i][amount]=min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(),vector<int>(1e4+1,-1));
        int ans=solve(0,amount,coins,memo);
        return ans>=1e5?-1:ans;
    }
};