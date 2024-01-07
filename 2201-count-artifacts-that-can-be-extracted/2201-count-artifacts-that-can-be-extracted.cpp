class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int extracted=0;
        vector<vector<bool>> ground(n,vector<bool>(n,false));
        for(auto pos:dig) ground[pos[0]][pos[1]]=true;
        for(auto artifact:artifacts) {
            bool dug_out=true;
            int r1=artifact[0],c1=artifact[1],r2=artifact[2],c2=artifact[3];
            for(int i=r1;i<=r2;i++) for(int j=c1;j<=c2;j++) if(!ground[i][j]) {
                dug_out=false;
                break;
            }
            if(dug_out) extracted++;
        }
        return extracted;
    }
};