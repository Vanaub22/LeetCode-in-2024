class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> answer(queries.size());
        for(int i=0;i<queries.size();i++) {
            int k=queries[i][0],trim=queries[i][1];
            vector<pair<string,int>> temp;
            for(int j=0;j<nums.size();j++) {
                string x=nums[j].substr(nums[j].size()-trim);
                temp.emplace_back(make_pair(x,j));
            }
            sort(temp.begin(),temp.end(),[&](auto& a, auto& b) {
                for(int t=0;t<a.first.length();t++) {
                    if(a.first[t]!=b.first[t]) {
                        return a.first[t]<b.first[t];
                    }
                }
                return a.second<b.second;
            });
            answer[i]=temp[k-1].second;
        }
        return answer;
    }
};