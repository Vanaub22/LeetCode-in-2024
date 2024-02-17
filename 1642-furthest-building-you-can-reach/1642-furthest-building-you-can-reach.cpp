// Greedy approach using min heap
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> ladderClimbs;
        int buildings=heights.size(),usedBricks=0;
        for(int i=1;i<buildings;i++) {
            if(heights[i]-heights[i-1]>0) ladderClimbs.push(heights[i]-heights[i-1]);
            if(ladderClimbs.size()>ladders) {
                usedBricks+=ladderClimbs.top();
                ladderClimbs.pop();
            }
            if(usedBricks>bricks) return i-1;
        }
        return buildings-1;
    }
};