class Solution {
public:
    void findCombinations(int idx, int target, vector<int>& candidates, vector<int>& combination, vector<vector<int>>& combinations){
        if(!target){
            combinations.push_back(combination);
            return;
        }
        int n=candidates.size();
        for(int i=idx;i<n;i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            combination.push_back(candidates[i]);
            findCombinations(i+1,target-candidates[i],candidates,combination,combinations);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> combinations;
        vector<int> combination;
        findCombinations(0,target,candidates,combination,combinations);
        return combinations;
    }
};