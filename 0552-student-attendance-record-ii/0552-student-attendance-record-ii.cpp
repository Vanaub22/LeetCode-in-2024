#define MOD 1000000007
class Solution {
private:
    int solve(int n, int consecutive_lates, int days_absent, auto& memo) {
        if(consecutive_lates>=3 || days_absent>=2) return 0;
        if(!n) return 1;
        if(memo[n][consecutive_lates][days_absent]!=-1) return memo[n][consecutive_lates][days_absent];
        int cnt=solve(n-1,0,days_absent,memo);
        cnt=(cnt+solve(n-1,consecutive_lates+1,days_absent,memo))%MOD;
        cnt=(cnt+solve(n-1,0,days_absent+1,memo))%MOD;
        return memo[n][consecutive_lates][days_absent]=cnt;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(n,0,0,memo);
    }
};