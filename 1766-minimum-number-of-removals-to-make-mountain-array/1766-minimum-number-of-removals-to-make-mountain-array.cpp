class Solution {
public:
    vector<int> find_all_LIS(auto& x) {
        int n=x.size();
        vector<int> ans(n,1),lis={x[0]};
        for(int i=1;i<n;i++) {
            if(x[i]>lis.back()) lis.push_back(x[i]);
            else {
                int index=lower_bound(lis.begin(),lis.end(),x[i])-lis.begin();
                lis[index]=x[i];
            }
            ans[i]=lis.size();
        }
        return ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis=find_all_LIS(nums);
        reverse(nums.begin(),nums.end());
        vector<int> lds=find_all_LIS(nums);
        reverse(lds.begin(),lds.end());
        int removals=INT_MAX;
        for(int i=0;i<n;i++) if(lis[i]>1 && lds[i]>1) removals=min(removals,n+1-lis[i]-lds[i]);
        return removals;
    }
};