class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        while(k--) {
            auto [x,i]=pq.top();
            x*=multiplier;
            pq.pop(),pq.push({x,i});
        }
        while(!pq.empty()) {
            auto [x,i]=pq.top();
            nums[i]=x;
            pq.pop();
        }
        return nums;
    }
};