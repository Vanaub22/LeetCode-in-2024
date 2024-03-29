class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // Starting from the index k and then greedily expanding outwards using two pointers
        int left=k,right=left,n=nums.size(),maxScore=-1,minimum=nums[k];
        bool moveLeft=true;
        while(left>=0 || right<=n-1) {
            maxScore=max(maxScore,minimum*(right-left+1));
            if(!left && right==n-1) break;
            if(!left) minimum=min(minimum,nums[++right]);
            else if(right==n-1) minimum=min(minimum,nums[--left]);
            else {
                moveLeft=nums[left-1]>nums[right+1];
                if(moveLeft) minimum=min(minimum,nums[--left]);
                else minimum=min(minimum,nums[++right]);
            }
        }
        return maxScore;
    }
};