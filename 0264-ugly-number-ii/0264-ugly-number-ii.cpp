class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[1690];
        dp[0]=1; // 1 is considered an ugly number
        int p2=0,p3=0,p5=0;
        for(int i=1;i<1690;i++) {
            dp[i]=min({dp[p2]*2,dp[p3]*3,dp[p5]*5});
            if(dp[i]==dp[p2]*2) p2++;
            if(dp[i]==dp[p3]*3) p3++;
            if(dp[i]==dp[p5]*5) p5++;
        }
        return dp[n-1];
    }
};