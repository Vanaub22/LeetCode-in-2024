class Solution {
private:
    int subarrysWithMaxKDistinct(auto& nums, int k) {
        int n=nums.size(),subarrays=0,left=0,right=left;
        unordered_map<int,int> f;
        while(right<n) {
            f[nums[right++]]++;
            while(f.size()>k) {
                f[nums[left]]--;
                if(!f[nums[left]]) f.erase(nums[left]);
                left++;
            }
            subarrays+=right-left+1;
        }
        return subarrays;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrysWithMaxKDistinct(nums,k)-subarrysWithMaxKDistinct(nums,k-1);
    }
};