class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        auto countValidPairs=[&nums,&n](int diff)->int {
            int left=0,right=1,cnt=0;
            while(right<n) {
                while(left<right && nums[right]-nums[left]>diff) left++;
                cnt+=right-left;
                right++;
            }
            return cnt;
        };
        sort(nums.begin(),nums.end());
        int left=0,right=nums[n-1];
        while(left<right) {
            int mid=left+(right-left)/2;
            if(countValidPairs(mid)<k) left=mid+1;
            else right=mid;
        }
        return left;        
    }
};