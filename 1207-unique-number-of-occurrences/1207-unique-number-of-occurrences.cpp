class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i:arr) freq[i]++;
        set<int> s;
        for(auto& it:freq) {
            if(s.find(it.second)==s.end()) s.insert(it.second);
            else return false;
        }
        return true;
    }
};