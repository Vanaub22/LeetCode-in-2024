class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(int i:nums) s.push_back(to_string(i));
        sort(s.begin(),s.end(),[&](auto& a, auto& b) {
            return a+b>b+a;
        });
        if(s[0]=="0") return "0";
        string ans="";
        for(string c:s) ans+=c;
        return ans;
    }
};