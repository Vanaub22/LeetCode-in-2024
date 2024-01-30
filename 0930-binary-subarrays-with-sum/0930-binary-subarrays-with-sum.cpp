class Solution {
public:
    // Hashing prefix sums to reduce T.C. to O(N)
    int numSubarraysWithSum(vector<int>& x, int g) {
        int n=x.size(),ans=0,pref[30000]={0};
        pref[0]++; // Initial prefix sum
        for(int i=0;i<n;i++) {
            if(i) x[i]+=x[i-1];
            if(x[i]>=g) ans+=pref[x[i]-g];
            pref[x[i]]++;
        }
        return ans;
    }
};