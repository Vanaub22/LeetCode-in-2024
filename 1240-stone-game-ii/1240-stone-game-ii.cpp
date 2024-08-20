class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> memo=vector<vector<vector<int>>>(2,vector<vector<int>>(101,vector<int>(101,-1)));
        function<int(bool,int,int)> solve=[&solve,&n,&piles,&memo](bool alicePicks, int i, int m)->int {
            if(i==n) return 0;
            if(memo[alicePicks][i][m]!=-1) return memo[alicePicks][i][m];
            int stones=alicePicks?0:INT_MAX,picked=0,xlim=min(2*m,n-i);
            for(int x=1;x<=xlim;x++) {
                picked+=piles[i+x-1];
                int M=max(m,x);
                if(alicePicks) stones=max(stones,picked+solve(false,i+x,M));
                else stones=min(stones,solve(true,i+x,M));
            }
            return memo[alicePicks][i][m]=stones; 
        };
        return solve(true,0,1);
    }
};