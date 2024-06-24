class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),minFlips=0;
        vector<int> prefixFlips(n+1,0);
        for(int i=0;i<n;i++) {
            if(i) prefixFlips[i]+=prefixFlips[i-1];
            if(i<n-k+1) {
                int bit=prefixFlips[i]%2?!nums[i]:nums[i];
                if(bit) continue;
                minFlips++;
                prefixFlips[i]++,prefixFlips[i+k]--;
            }
        }
        for(int i=0;i<n;i++) {
            int bit=prefixFlips[i]%2?!nums[i]:nums[i];
            if(!bit) return -1;
        }
        return minFlips;
    }
};