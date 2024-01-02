class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums) freq[i]++;
        vector<vector<int>> ans;
        bool empty=false; // Flag to denote if all the elements have been included
        while(!empty) {
            empty=true;
            vector<int> nRow;
            for(auto& it:freq) {
                if(it.second>0) {
                    nRow.push_back(it.first);
                    it.second--; // One occurrence included in one row of answer
                }
                if(it.second>0) empty=false;
            }
            ans.push_back(nRow);
        }
        return ans;
    }
};