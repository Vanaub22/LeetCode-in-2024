class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),left=0,cnt=0,highest=*max_element(nums.begin(),nums.end());
        long long res=0;
        for(int right=0;right<n;right++) {
            if(nums[right]==highest) cnt++;
            while(cnt>=k) {
                res+=n-right;
                if(nums[left]==highest) cnt--;
                left++;
            }
        }
        return res;
    }
};