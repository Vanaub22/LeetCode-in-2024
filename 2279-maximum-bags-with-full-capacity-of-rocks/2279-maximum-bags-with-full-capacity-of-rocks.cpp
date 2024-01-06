class Solution {
public:
    // Greedy Approach
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // The easiest bags to fill will be the ones with the least empty space available
        // Lets compute the available spaces in each bag first
        int n=capacity.size(),filled=0;
        for(int i=0;i<n;i++) capacity[i]-=rocks[i]; // Reducing to available capacity
        // Sorting the bags in order of increasing empty space available
        sort(capacity.begin(),capacity.end());
        while(additionalRocks>0 && filled<n) additionalRocks-=capacity[filled++];
        return additionalRocks<0?filled-1:filled; // The last bag might not be fully filled
    }
};