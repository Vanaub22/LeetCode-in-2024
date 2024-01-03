#define STONE '#'
#define OBSTACLE '*'
#define EMPTY '.'
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        // Implementing stone fall logic
        for(int i=0;i<m;i++) {
            int stones=0;
            for(int j=0;j<n;j++) {
                if(box[i][j]==STONE) stones++;
                if(box[i][j]==OBSTACLE || j==n-1)  {
                    int k=box[i][j]==OBSTACLE?j-1:j;
                    for(;k>=0 && box[i][k]!=OBSTACLE;k--) {
                        if(stones) {
                            box[i][k]=STONE;
                            stones--;
                        }
                        else box[i][k]=EMPTY;
                    }
                }
            }
        }
        // Rotation Logic
        vector<vector<char>> rotated;
        for(int i=0;i<n;i++) {
            vector<char> row;
            for(int j=m-1;j>=0;j--) row.push_back(box[j][i]);
            rotated.push_back(row);
        }
        return rotated;
    }
};