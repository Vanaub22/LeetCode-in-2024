class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans={0,INT_MAX};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int ub=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++) {
            pq.push(make_pair(nums[i][0],make_pair(i,0)));
            ub=max(ub,nums[i][0]);
        }
        while(!pq.empty()) {
            auto entry=pq.top();
            int lb=entry.first,i=entry.second.first,j=entry.second.second;
            pq.pop();
            if(ub-lb<ans[1]-ans[0] || ub-lb==ans[1]-ans[0] && lb<ans[0]) ans[0]=lb,ans[1]=ub;
            if(j+1<nums[i].size()) {
                pq.push(make_pair(nums[i][j+1],make_pair(i,j+1)));
                ub=max(ub,nums[i][j+1]);
            }
            else break;
        }
        return ans;
    }
};