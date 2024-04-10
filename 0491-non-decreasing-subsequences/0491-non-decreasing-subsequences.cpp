class Solution {
private:
    void generate(auto& x, int idx, auto& s, auto& curr) {
        if(curr.size()>=2) s.insert(curr);
        if(idx>=x.size()) return;
        for(int i=idx;i<x.size();i++) {
            if(curr.empty() || curr.back()<=x[i]) {
                curr.emplace_back(x[i]);
                generate(x,i+1,s,curr);
                curr.pop_back(); // Backtracking
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> curr;
        generate(nums,0,s,curr);
        return vector<vector<int>>(s.begin(),s.end());
    }
};