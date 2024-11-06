class Solution {
public:
    int countSetBits(int x) {
        int cnt=0;
        while(x>0) {
            cnt+=x&1;
            x>>=1;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size(),sbc[100],idx=0,s=0;
        memset(sbc,0,sizeof(sbc));
        for(int i:nums) sbc[idx++]=countSetBits(i);
        while(s<n) {
            for(int i=1;i<n;i++) if((sbc[i]==sbc[i-1]) && nums[i]<nums[i-1]) swap(nums[i],nums[i-1]);
            bool sorted=1;
            for(int i=0;i<n-1;i++) if(nums[i]>nums[i+1]) {
                sorted=false;
                break;
            }
            if(sorted) return true;
            s++;
        }
        return false;
    } 
};

