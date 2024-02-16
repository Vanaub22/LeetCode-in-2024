class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(int i:arr) freq[i]++;
        int removals=0;
        vector<int> tmp;
        for(auto it:freq) tmp.push_back(it.second);
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();i++) {
            if(k-tmp[i]>=0) {
                k-=tmp[i];
                removals++;
            }
            if(!k) break;
        }
        return tmp.size()-removals;
    }
};