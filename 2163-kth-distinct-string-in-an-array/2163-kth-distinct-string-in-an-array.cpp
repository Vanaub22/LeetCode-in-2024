class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> f;
        for(string& s:arr) f[s]++;
        for(string& s:arr) {
            if(f[s]==1) k--;
            if(!k) return s;
        }
        return "";
    }
};