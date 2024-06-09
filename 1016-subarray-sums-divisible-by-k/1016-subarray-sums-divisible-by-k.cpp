// Optimized Solution (Typical Approach) involving Prefix Sum
// O(N) T.C. and O(k) S.C.
// Let p and q be 2 prefix sums at different points in the array
// Let us assume that p and q have the same remainder r when divided by k
// Therefore, p and q can be written as p = k x q1 + r and q = k x q2 + r
// => p - q = k x (q1 - q2) => the subarray between p and q is divisible by k
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Converting to prefix sum array
        int pfs=0,ans=0;
        unordered_map<int,int> rem={{0,1}};
        for(int i:nums) {
            pfs+=i;
            int r=pfs%k;
            if(r<0) r+=k;
            ans+=rem[r]++;
        }
        return ans;
    }
};