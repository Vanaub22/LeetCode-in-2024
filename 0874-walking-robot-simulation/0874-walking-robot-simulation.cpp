class Solution {
private:
    // Helper fn. to obtain direction after turning left by 90 degrees
    void turnLeft(char& dir) {
        if(dir=='N') dir='W';
        else if(dir=='W') dir='S';
        else if(dir=='S') dir='E';
        else dir='N';
    }
    // Helper fn. to obtain direction after turning right by 90 degrees
    void turnRight(char& dir) {
        if(dir=='N') dir='E';
        else if(dir=='E') dir='S';
        else if(dir=='S') dir='W';
        else dir='N';
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dist=0;
        char dir='N';
        vector<int> pos={0,0}; // Initial position
        set<vector<int>> obs(obstacles.begin(),obstacles.end());
        for(int& command:commands) {
            if(command==-2) turnLeft(dir);
            else if(command==-1) turnRight(dir);
            else {
                for(int i=0;i<command;i++) {
                    // Moving forward
                    if(dir=='N') pos[1]++;
                    else if(dir=='S') pos[1]--;
                    else if(dir=='E') pos[0]++;
                    else pos[0]--;
                    if(obs.find(pos)!=obs.end()) {
                        // Obstacle encountered => Taking a step backward
                        if(dir=='N') pos[1]--;
                        else if(dir=='S') pos[1]++;
                        else if(dir=='E') pos[0]--;
                        else pos[0]++;
                        continue; // Moving to the next command
                    }
                    dist=max(dist,pos[0]*pos[0]+pos[1]*pos[1]);
                }
            }
        }
        return dist;
    }
};