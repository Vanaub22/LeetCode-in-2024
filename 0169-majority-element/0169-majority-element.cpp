class Solution {
public:
    // Boyer-Moore's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int x=-1,cnt=0;
        for(int i:nums) {
            if(!cnt) {
                x=i;
                cnt=1;
            }
            else if(x==i) cnt++;
            else cnt--;
        }
        return x;
    }
};