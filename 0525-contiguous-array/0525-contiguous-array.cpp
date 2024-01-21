class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt=0,n=nums.size(),res=0;
        unordered_map<int,int> umap;
        umap[0]=-1;
        for(int i=0;i<n;i++) {
            cnt+=nums[i]?1:-1;
            if(umap.find(cnt)!=umap.end()) res=max(res,i-umap[cnt]);
            else umap[cnt]=i;
        }
        return res;
    }
};