class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> freq;
        for(int card:deck) freq[card]++;
        int x=freq.begin()->second;
        for(auto it:freq) {
            if(it.second==1 || gcd(x,it.second)==1) return false;
            else x=it.second<x?it.second:x;
        }
        return true;
    }
};