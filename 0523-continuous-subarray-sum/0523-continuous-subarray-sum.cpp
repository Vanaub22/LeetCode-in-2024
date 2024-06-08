class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(),pfs=0,r;
        unordered_map<int,int> rem_index={{0,-1}};
        for(int i=0;i<n;i++) {
            pfs+=nums[i],r=pfs%k;
            if(rem_index.find(r)==rem_index.end()) rem_index[r]=i;
            else if(i-rem_index[r]>1) return true;
        }
        return false;
    }
};