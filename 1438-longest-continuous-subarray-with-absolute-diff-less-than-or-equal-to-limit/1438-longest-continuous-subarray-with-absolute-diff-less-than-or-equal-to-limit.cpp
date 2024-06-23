class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        int left=0,right=0,n=nums.size(),ans=0;
        while(right<n) {
            maxHeap.push({nums[right],right}),minHeap.push({nums[right],right});
            while(maxHeap.top().first-minHeap.top().first>limit) {
                int boundary=min(maxHeap.top().second,minHeap.top().second);
                while(minHeap.top().second<=boundary) minHeap.pop();
                while(maxHeap.top().second<=boundary) maxHeap.pop();
                left=boundary+1;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};