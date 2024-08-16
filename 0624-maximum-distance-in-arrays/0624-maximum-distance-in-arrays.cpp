class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size(),d1=INT_MIN,d2=INT_MIN,d3=INT_MIN,d4=INT_MIN;
        pair<int,int> min1={-1,INT_MAX},min2={-1,INT_MAX},max1={-1,INT_MIN},max2={-1,INT_MIN};
        for(int i=0;i<m;i++) {
            int n=arrays[i].size(),a=arrays[i][0],b=arrays[i][n-1];
            if(a<min1.second) {
                min2=min1;
                min1={i,a};
            }
            else if(a<min2.second && a>=min1.second) {
                min2={i,a};
            }
            if(b>max1.second) {
                max2=max1;
                max1={i,b};
            }
            else if(b>max2.second && b<=max1.second) {
                max2={i,b};
            }
        }
        if(min1.first!=max1.first && min1.first!=-1 && max1.first!=-1) d1=max1.second-min1.second;
        if(min1.first!=max2.first && min1.first!=-1 && max2.first!=-1) d2=max2.second-min1.second;
        if(min2.first!=max1.first && min2.first!=-1 && max1.first!=-1) d3=max1.second-min2.second;
        if(min2.first!=max1.first && min2.first!=-1 && max1.first!=-1) d4=max2.second-min2.second;
        return max({d1,d2,d3,d4});
    }
};