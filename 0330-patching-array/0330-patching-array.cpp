class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int cost=0,m=nums.size(),i=0;
        long long int upperlim=0;
        while(upperlim<n) {
            if(i<m && nums[i]<=upperlim+1) {
                upperlim+=nums[i];
                i++;
            }
            else {
                cost++;
                upperlim+=upperlim+1;
            }
        }
        return cost;
    }
};