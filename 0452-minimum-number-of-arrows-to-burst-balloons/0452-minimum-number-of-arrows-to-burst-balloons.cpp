class Solution {
public:
    // Greedy Approach
    int findMinArrowShots(vector<vector<int>>& balloons) {
        sort(balloons.begin(),balloons.end());
        int n=balloons.size(),boundary=balloons[0][1],arrows=1;
        for(int i=1;i<n;i++) {
            if(boundary>=balloons[i][0]) boundary=min(boundary,balloons[i][1]);
            else {
                // No overlap => Another arrow has to be shot
                arrows++;
                boundary=balloons[i][1];
            }
        }
        return arrows;
    }
};