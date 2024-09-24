class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        unordered_map<int,int> memo;
        for(auto& word:dictionary) dict.insert(word);
        int n=s.size();
        function<int(int)> dp=[&](int idx)->int {
            if(idx>=n) return 0;
            if(memo.find(idx)!=memo.end()) return memo[idx];
            int ans=INT_MAX;
            string word="";
            for(int i=idx;i<n;i++) {
                word+=s[i];
                if(dict.find(word)!=dict.end()) ans=min(ans,dp(i+1));
            }
            ans=min(ans,1+dp(idx+1));
            return memo[idx]=ans;
        };
        return dp(0);
    }
};