class Solution {
public:
    // Brute Force Solution
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> freq;
        int comp_subarrays=0;
        for(int i:nums) freq[i]++;
        int k=freq.size(),n=nums.size();
        for(int i=0;i<n;i++) {
            freq.clear();
            for(int j=i;j<n;j++) {
                freq[nums[j]]++;
                if(freq.size()==k) comp_subarrays++;
            }
        }
        return comp_subarrays;
    }
};