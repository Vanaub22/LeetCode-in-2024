class Solution {
public:
    // Memoizing the recursive soln.
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size(),memo[n];
        memset(memo,-1,sizeof(memo));
        return findMax(arr,k,0,memo,n);
    }
    int findMax(vector<int>& arr, int k, int start, int memo[], int n) {
        if(start>=n) return 0;
        if(memo[start]!=-1) return memo[start];
        int maxSoFar=0,ans=0;
        for(int i=start;i<min(start+k,n);i++) {
            maxSoFar=max(maxSoFar,arr[i]);
            ans=max(ans,maxSoFar*(i-start+1)+findMax(arr,k,i+1,memo,n));
        }
        return memo[start]=ans;        
    }
};