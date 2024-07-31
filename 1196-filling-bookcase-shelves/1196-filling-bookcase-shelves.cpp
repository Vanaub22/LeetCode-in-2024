class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size(),memo[n+1];
        fill(memo,memo+n,-1);
        function<int(int)> solve=[&](int i)->int {
            if(i==n) return 0;
            if(memo[i]!=-1) return memo[i];
            int cur_width=shelfWidth,max_height=0,ans=INT_MAX;
            for(int j=i;j<n;j++) {
                int width=books[j][0],height=books[j][1];
                if(cur_width<width) break;
                cur_width-=width;
                max_height=max(max_height,height);
                ans=min(ans,solve(j+1)+max_height);
            }
            return memo[i]=ans;
        };
        return solve(0);
    }
};