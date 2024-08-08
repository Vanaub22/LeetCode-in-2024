class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        bool east=true,north=false,south=false,west=false; // Direction of movement
        vector<vector<int>> coordinates={{rStart,cStart}};
        int r=rStart,c=cStart,side=0,move=0;
        while(coordinates.size()<rows*cols) {
            if(move%2==0) side++; // The side length increases at every 3rd move
            move++;
            for(int i=0;i<side;i++) {
                if(east) c++;
                else if(south) r++;
                else if(west) c--;
                else r--;
                if(r>=0 && r<rows && c>=0 && c<cols) coordinates.push_back({r,c});
            }
            // Changing directions in a spiral manner
            if(east) {
                east=false;
                south=true;
            }
            else if(south) {
                south=false;
                west=true;
            }
            else if(west) {
                west=false;
                north=true;
            }
            else {
                north=false;
                east=true;
            }
        }
        return coordinates;
    }
};