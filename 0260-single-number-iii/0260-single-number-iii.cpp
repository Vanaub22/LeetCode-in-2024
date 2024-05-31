class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0,shift=0,a=0,b=0;
        for(int i:nums) x^=i;
        while(((x>>shift)&1)==0) shift++;
        for(int i:nums) {
            if(((i>>shift)&1)==0) a^=i;
            else b^=i;
        }
        return {a,b};
    }
};