class Solution {
public:
    // O(N) solution using Kadane's algorithm
    int maxAbsoluteSum(vector<int>& nums) {
        int msub=0,psub=0,max_pos=INT_MIN,min_neg=INT_MAX;
        for(int i=0;i<nums.size();i++) {
            psub+=nums[i];
            msub+=nums[i];
            if(psub>max_pos) max_pos=max(max_pos,psub);
            if(msub<min_neg) min_neg=min(min_neg,msub);
            if(psub<0) psub=0;
            if(msub>0) msub=0;
        }
        return max_pos>-min_neg?max_pos:-min_neg;
    }
};