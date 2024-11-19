class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long window_sum=0,ans=0;
        unordered_map<int,int> f;
        for(int i=0;i<n;i++) {
            f[nums[i]]++;
            window_sum+=nums[i];
            if(i>=k) {
                int leftmost=nums[i-k];
                f[leftmost]--;
                window_sum-=leftmost;
                if(!f[leftmost]) f.erase(leftmost);
            }
            if(f.size()==k) ans=max(ans,window_sum);
        }
        return ans;
    }
};