
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxNR=-1;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int cnt=0;
                for(auto& road:roads) if(road[0]==i || road[1]==i || road[0]==j || road[1]==j) cnt++;
                maxNR=max(maxNR,cnt);
            }
        }
        return maxNR;
    }
};