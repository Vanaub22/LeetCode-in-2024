class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string,vector<string>> umap;
        for(string& str:strs) {
            string s=str;
            sort(str.begin(),str.end());
            umap[str].push_back(s);
        }
        for(auto it:umap) if(it.second.size()>0) anagrams.push_back(it.second);
        return anagrams;
    }
};