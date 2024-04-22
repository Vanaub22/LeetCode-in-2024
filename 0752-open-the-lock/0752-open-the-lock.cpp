class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited={"0000"};
        unordered_set<string> d(deadends.begin(),deadends.end());
        if(d.find("0000")!=d.end()) return -1; // If the source node is a dead end
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty()) {
            auto [combination,moves]=q.front();
            q.pop();
            if(combination==target) return moves;
            for(int i=0;i<4;i++) {
                // Generating possible combinations
                for(int delta:{-1,1}) {
                    auto new_combination=combination;
                    new_combination[i]+=delta;
                    if(new_combination[i]<'0') new_combination[i]='9';
                    if(new_combination[i]>'9') new_combination[i]='0';
                    if(visited.find(new_combination)==visited.end() && d.find(new_combination)==d.end()) {
                        visited.insert(new_combination);
                        q.push({new_combination,moves+1});
                    }
                }
            }
        }
        return -1;
    }
};