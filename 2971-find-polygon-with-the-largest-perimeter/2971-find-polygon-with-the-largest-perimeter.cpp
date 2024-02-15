class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long select,prefsum=0;
        for(int i=nums.size()-1;i>=0;i--) {
            select=nums[i];
            prefsum=0;
            for(int j=0;j<=i-1;j++) prefsum+=nums[j];
            if(prefsum>select) break;
        }
        if(prefsum<=select) return -1;
        return prefsum+select;
    }
};  