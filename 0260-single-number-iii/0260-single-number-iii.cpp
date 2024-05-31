class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0,shift=0,a=0,b=0;
        for(int i:nums) x^=i; // Will yield a^b where a and b are the required numbers
        while(((x>>shift)&1)==0) shift++; // Finding the rightmost unequal bit between a and b
        for(int i:nums) {
            if(((i>>shift)&1)==0) a^=i;
            else b^=i;
        }
        return {a,b};
    }
};