class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> indices(n);
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&nums](int& a, int& b) {
            return nums[a]!=nums[b]?nums[a]<nums[b]:a<b;
        });
        int minIndex=n,maxWidth=0;
        for(int index:indices) {
            maxWidth=max(maxWidth,index-minIndex);
            minIndex=min(minIndex,index);
        }
        return maxWidth;
    }
};