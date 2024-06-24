class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),minFlips=0;
        auto flip=[&nums](int flips, int i)->int {
            return flips%2?!nums[i]:nums[i];
        };
        vector<int> prefixFlips(n+1,0);
        for(int i=0;i<n;i++) {
            if(i) prefixFlips[i]+=prefixFlips[i-1];
            if(i<n-k+1) {
                if(flip(prefixFlips[i],i)) continue;
                minFlips++;
                prefixFlips[i]++,prefixFlips[i+k]--;
            }
        }
        for(int i=0;i<n;i++) if(!flip(prefixFlips[i],i)) return -1;
        return minFlips;
    }
};