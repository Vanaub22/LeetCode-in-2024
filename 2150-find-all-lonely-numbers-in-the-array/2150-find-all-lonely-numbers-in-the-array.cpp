class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        set<int> lonely;
        unordered_map<int,int> freq;
        for(int i:nums) freq[i]++;
        for(auto& it:freq) {
            int x=it.first,f=it.second;
            if(f==1 && freq.find(x+1)==freq.end() && freq.find(x-1)==freq.end()) lonely.insert(x);
        }
        return vector<int>(lonely.begin(),lonely.end());
    }
};