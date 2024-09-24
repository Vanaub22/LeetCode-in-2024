class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s;
        for(int x:arr1) {
            string str=to_string(x),tmp="";
            for(int i=0;i<str.size();i++) {
                tmp+=str[i];
                if(s.find(tmp)==s.end()) s.insert(tmp);
            }
        }
        int ans=0;
        for(int x:arr2) {
            string str=to_string(x),tmp="";
            for(int i=0;i<str.size();i++) {
                tmp+=str[i];
                if(s.find(tmp)!=s.end()) ans=max(ans,(int)tmp.size());
            }
        }
        return ans;
    }
};