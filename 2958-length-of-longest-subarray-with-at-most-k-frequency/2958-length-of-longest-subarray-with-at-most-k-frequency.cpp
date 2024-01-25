class Solution {
public:
    // Classic Sliding Window
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i=0,w_start=0,res;
        for(;i<nums.size();i++) {
            if(freq[nums[i]]==k) break;
            freq[nums[i]]++;
        }
        res=i;
        for(;i<nums.size();i++) {
            freq[nums[i]]++;
            while(freq[nums[i]]>k && w_start<i) freq[nums[w_start++]]--;
            res=max(res,i-w_start+1);
        }
        return res;
    }
};