class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),low=0,high=n-1;
        while(low<=high) {
            int mid=low+(high-low)/2,cnt=0;
            for(int i:nums) if(i<=mid) cnt++;
            if(cnt<=mid) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};