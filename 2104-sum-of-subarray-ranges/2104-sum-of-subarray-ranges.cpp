class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n-1;i++) {
            int largest=nums[i],smallest=nums[i];
            for(int j=i+1;j<n;j++) {
                smallest=min(smallest,nums[j]);
                largest=max(largest,nums[j]);
                res+=largest-smallest;
            }
        }
        return res;
    }
};