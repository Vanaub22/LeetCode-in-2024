class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size(),curr=0,target=0,ans=n+1;
        for(int i:nums) target=(target+i)%p;
        if(!target) return 0;
        unordered_map<int,int> moduloMap;
        moduloMap[0]=-1;
        for(int i=0;i<n;i++) {
            curr=(curr+nums[i])%p;
            int reqd=(curr-target+p)%p;
            if(moduloMap.find(reqd)!=moduloMap.end()) ans=min(ans,i-moduloMap[reqd]);
            moduloMap[curr]=i;
        }
        return ans==n?-1:ans;
    }
};