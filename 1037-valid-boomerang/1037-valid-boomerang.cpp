class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
        if(p[0]==p[1] || p[1]==p[2] || p[2]==p[0]) return false;
        int x1=p[0][0],y1=p[0][1],x2=p[1][0],y2=p[1][1],x3=p[2][0],y3=p[2][1];
        if(x2-x1==0 || x3-x1==0) return x3-x1==0^x2-x1==0;
        return (float)(y2-y1)/(x2-x1)!=(float)(y3-y1)/(x3-x1);
    }
};