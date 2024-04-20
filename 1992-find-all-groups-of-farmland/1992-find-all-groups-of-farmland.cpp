class Solution {
private:
    // Helper DFS fn. to explore current piece of farmland and find the bottom-right corner
    void exp(int i, int j, int& br_x, int& br_y, vector<vector<int>>& land, int m, int n) {
        if(i<0 || i>m-1 || j<0 || j>n-1 || !land[i][j]) return;
        land[i][j]=0; // Marking as visited
        br_x=max(br_x,i);
        br_y=max(br_y,j);
        exp(i+1,j,br_x,br_y,land,m,n);
        exp(i,j+1,br_x,br_y,land,m,n);
        exp(i-1,j,br_x,br_y,land,m,n);
        exp(i,j-1,br_x,br_y,land,m,n);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int m=land.size(),n=land[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(land[i][j]) {
                    int tl_x=i,tl_y=j,br_x=0,br_y=0;
                    exp(i,j,br_x,br_y,land,m,n);
                    res.push_back({tl_x,tl_y,br_x,br_y});
                }
            }
        }
        return res;
    }
};