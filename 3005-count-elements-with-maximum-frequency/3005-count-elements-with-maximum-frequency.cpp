class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums) freq[i]++;
        int mfreq=-1,ans=0;
        for(auto it:freq) mfreq=max(mfreq,it.second);
        for(int i:nums) if(freq[i]==mfreq) ans++;
        return ans;
    }
};