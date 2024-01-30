class Solution {
public:
    // Hashing prefix sums to reduce T.C. to O(N)
    int numSubarraysWithSum(vector<int>& x, int goal) {
        int n=x.size(),ans=0;
        unordered_map<int,int> umap;
        umap[0]++; // Initial prefix sum
        for(int i=0;i<n;i++) {
            if(i) x[i]+=x[i-1];
            if(x[i]>=goal) ans+=umap[x[i]-goal];
            umap[x[i]]++;
        }
        return ans;
    }
};