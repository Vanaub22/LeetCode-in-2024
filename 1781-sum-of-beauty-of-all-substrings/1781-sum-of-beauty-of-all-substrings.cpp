class Solution {
public:
    // Brute Force Solution
    int beautySum(string s) {
        int n=s.length(),beauty_sum=0;
        for(int i=0;i<n;i++) {
            unordered_map<int,int> freq;
            for(int j=i;j<n;j++) {
                freq[s[j]]++;
                int highest_freq=INT_MIN,lowest_freq=INT_MAX;
                for(auto it:freq) {
                    highest_freq=max(highest_freq,it.second);
                    lowest_freq=min(lowest_freq,it.second);
                }
                beauty_sum+=highest_freq-lowest_freq;
            }
        }
        return beauty_sum;
    }
};