class Solution {
public:
    int specialArray(vector<int>& nums) {
        int g=*max_element(nums.begin(),nums.end());
        for(int x=0;x<=g;x++) {
            int cnt=0;
            for(int i:nums) if(i>=x) cnt++;
            if(cnt==x) return x;
        }
        return -1;
    }
};