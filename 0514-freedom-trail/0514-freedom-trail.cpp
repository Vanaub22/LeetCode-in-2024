class Solution {
private:
    int dp(int r, int k, auto& ring, auto& key, auto& memo) {
        if(k==key.size()) return 0;
        int res=INT_MAX;
        if(memo[r][k]!=-1) return memo[r][k];
        for(int i=0;i<ring.size();i++) {
            if(ring[i]==key[k]) {
                int space_between=abs(r-i),space_around=ring.size()-space_between;
                res=min(res,min(space_between,space_around)+1+dp(i,k+1,ring,key,memo));
            }
        }
        return memo[r][k]=res;
    }
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> memo(ring.size(),vector<int>(key.size(),-1));
        return dp(0,0,ring,key,memo);
    }
};