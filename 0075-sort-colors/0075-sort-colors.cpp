class Solution {
public:
    void sortColors(vector<int>& nums) {
        int f[3]={0};
        for(int i:nums) f[i]++;
        for(int i=0;i<nums.size();i++) {
            if(f[0]) {
                nums[i]=0;
                f[0]--;
            }
            else if(f[1]) {
                nums[i]=1;
                f[1]--;
            }
            else nums[i]=2;
        }
    }
};