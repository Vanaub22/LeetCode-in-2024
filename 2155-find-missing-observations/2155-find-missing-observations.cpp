class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size(),sum=(m+n)*mean-accumulate(rolls.begin(),rolls.end(),0),value=6;
        if(n>sum || n*6<sum) return {};
        vector<int> ans;
        for(int i=1;i<=n;i++) {
            while(value>=1 && sum-value<n-i) value--;
            sum-=value;
            ans.push_back(value);
        }
        return ans;

    }
};