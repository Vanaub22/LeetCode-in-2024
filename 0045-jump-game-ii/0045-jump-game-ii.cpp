class Solution {
public:
    // Greedy Approach
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int pos=0,jumps=0,max_reachable=0;
        while(pos<n) {
            // Creating a new window of possible indices that can be reached from current window
            int wlim=max_reachable;
            max_reachable=pos;
            for(int i=pos;i<=wlim;i++) max_reachable=max(max_reachable,i+nums[i]);
            jumps++;
            if(max_reachable>=n-1) break;
            pos++;
        }
        return jumps;
    }
};