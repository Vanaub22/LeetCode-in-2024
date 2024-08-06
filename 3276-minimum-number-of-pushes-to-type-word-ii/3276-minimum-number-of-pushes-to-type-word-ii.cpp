class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freq;
        for(char c:word) freq[c]++;
        vector<int> frequencies;
        for(auto& [c,f]:freq) frequencies.push_back(f);
        sort(frequencies.rbegin(),frequencies.rend());
        int ans=0,allocated=0,presses_required=1;
        for(int f:frequencies) {
            ans+=f*presses_required;
            allocated++;
            if(allocated%8==0) presses_required++;
        }
        return ans;
    }
};