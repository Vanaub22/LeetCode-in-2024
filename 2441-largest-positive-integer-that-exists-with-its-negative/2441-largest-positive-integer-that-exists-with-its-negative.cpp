class Solution {
private:
    bool binarySearch(int k, int left, vector<int>& nums) {
        int right=nums.size()-1;
        while(left<=right) {
            int mid=left+(right-left)/2;
            // Binary search onditions reversed because the array is sorted in descending order
            if(k<nums[mid]) left=mid+1;
            else if(k>nums[mid]) right=mid-1;
            else return true;
        }
        return false;
    }
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size();i++) if(binarySearch((-1)*nums[i],i,nums)) return nums[i];
        return -1;
    }
};