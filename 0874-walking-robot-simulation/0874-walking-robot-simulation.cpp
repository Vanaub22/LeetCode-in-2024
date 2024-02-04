#define RIGHT -1
class Solution {
private:
    // Helper fn. to obtain direction after turning left/right by 90 degrees
    void turn(char& dir, int command) {
        if(dir=='N') dir=command==RIGHT?'E':'W';
        else if(dir=='E') dir=command==RIGHT?'S':'N';
        else if(dir=='S') dir=command==RIGHT?'W':'E';
        else dir=command==RIGHT?'N':'S';
    }
    // Helper fn. to move forward/backward and update position
    void move(char dir, auto& pos, int step) {
        if(dir=='N') pos[1]+=step;
        else if(dir=='S') pos[1]-=step;
        else if(dir=='E') pos[0]+=step;
        else pos[0]-=step;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dist=0;
        char dir='N';
        vector<int> pos={0,0}; // Initial position
        set<vector<int>> obs(obstacles.begin(),obstacles.end());
        for(int& command:commands) {
            if(command<0) turn(dir,command);
            else {
                for(int i=0;i<command;i++) {
                    // Moving forward along the current direction by one step
                    move(dir,pos,1);
                    if(obs.find(pos)!=obs.end()) {
                        // Obstacle encountered => Taking a step backward
                        move(dir,pos,-1);
                        continue; // Moving to the next command
                    }
                    dist=max(dist,pos[0]*pos[0]+pos[1]*pos[1]);
                }
            }
        }
        return dist;
    }
};