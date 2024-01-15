class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer(2);
        map<int,int> losses; // Using std::map for implicit sorting
        for(auto match:matches) {
            losses[match[0]]+=0; // For creating the entry (if absent in map)
            losses[match[1]]++;
        }
        for(auto it:losses) {
            if(!it.second) answer[0].emplace_back(it.first);
            else if(it.second==1) answer[1].emplace_back(it.first);
        }
        return answer;
    }

};