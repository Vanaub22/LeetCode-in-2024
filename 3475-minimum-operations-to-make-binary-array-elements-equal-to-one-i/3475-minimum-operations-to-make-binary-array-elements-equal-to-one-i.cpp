class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),operations=0;
        auto flip=[&nums,n,&operations](int x)->bool {
            for(int i=0;i<3;i++) {
                if(x+i<n) nums[x+i]=!nums[x+i];
                else return false;
            }
            operations++;
            return true;
        };
        for(int i=0;i<n;i++) if(!nums[i]) if(!flip(i)) return -1;
        return operations;
    }
};