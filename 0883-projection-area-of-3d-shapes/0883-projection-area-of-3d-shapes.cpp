class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size(),xy_area=0,yz_area=0,xz_area=0;
        vector<int> highest_in_col(n,0);
        for(vector<int>& row:grid) {
            int highest_in_row=0;
            for(int i=0;i<n;i++) {
                if(row[i]) { 
                    xy_area++; // All non-zero entries
                    highest_in_row=max(highest_in_row,row[i]); // Highest value in row
                    highest_in_col[i]=max(highest_in_col[i],row[i]); // Highest column values
                } 
            }
            xz_area+=highest_in_row;
        }
        yz_area=accumulate(highest_in_col.begin(),highest_in_col.end(),0);
        return xy_area+yz_area+xz_area;
    }
};