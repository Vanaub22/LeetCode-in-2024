class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto& query:queries) {
            int x=0;
            for(int i=query[0];i<=query[1];i++) x^=arr[i];
            ans.emplace_back(x);
        }
        return ans;
    }
};