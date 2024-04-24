class Solution {
private:
    int dp(int n, auto& memo) {
        if(n<=2) return memo[n]=n!=0;
        else if(memo[n]!=-1) return memo[n];
        else return memo[n]=dp(n-1,memo)+dp(n-2,memo)+dp(n-3,memo);
    }
public:
    int tribonacci(int n) {
        vector<int> memo(n+1,-1);
        return dp(n,memo);
    }
};