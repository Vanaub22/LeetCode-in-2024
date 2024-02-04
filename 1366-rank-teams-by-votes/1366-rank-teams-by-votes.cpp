class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ranking=votes[0];
        int n=ranking.size();
        vector<vector<int>> positionalVotes(26,vector<int>(n,0));
        for(auto& vote:votes) for(int i=0;i<n;i++) positionalVotes[vote[i]-'A'][i]++;
        // Custom comparison for each position
        sort(ranking.begin(),ranking.end(),[&](char& a, char& b) {
            for(int i=0;i<n;i++) {
                if(positionalVotes[a-'A']!=positionalVotes[b-'A']) {
                    return positionalVotes[a-'A']>positionalVotes[b-'A'];
                }
            }
            return a<b;
        });
        return ranking;
    }
};