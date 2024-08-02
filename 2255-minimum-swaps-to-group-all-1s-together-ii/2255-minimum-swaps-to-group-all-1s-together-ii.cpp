class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0,n=nums.size(),cnt=0,minCnt=n;
        for(int i=0;i<n;i++) {
            k+=nums[i];
            nums.push_back(nums[i]);
        }
        if(!k) return 0;
        n=nums.size();
        for(int i=0;i<k;i++) cnt+=!nums[i];
        for(int i=k;i<n;i++) {
            cnt+=!nums[i]-!nums[i-k];
            minCnt=min(minCnt,cnt);
        }
        return minCnt;
    }
};