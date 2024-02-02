class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<10;i++) gen(to_string(i),low,high,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void gen(string s, int low, int high, vector<int>& ans) {
        int n=stoi(s);
        if(n>high) return;
        if(n>=low && n<=high) ans.emplace_back(n);
        if(s.back()=='9') return;
        s+=s.back()+1;
        gen(s,low,high,ans);
    }
};