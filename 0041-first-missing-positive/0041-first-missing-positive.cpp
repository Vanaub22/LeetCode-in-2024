class Solution {
public:
    // Leveraging constraints to reduce T.C. and S.C. to O(1)
    int firstMissingPositive(vector<int>& nums) {
        int i,hmap[100002]={0}; // O(1) Space
        for(int i:nums) if(i>0 && i<100001) hmap[i]=1;
        for(i=1;i<100002;i++) if(!hmap[i]) break;
        return i;
    }
};