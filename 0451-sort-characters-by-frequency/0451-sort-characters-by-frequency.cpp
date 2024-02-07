class Solution {
public:
    string frequencySort(string& s) {
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        sort(s.begin(),s.end(),[&](char& a, char& b) {
            return freq[a]!=freq[b]?freq[a]>freq[b]:a<b; 
        });
        return s;
    }
};