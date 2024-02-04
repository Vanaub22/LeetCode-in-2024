class Solution {
public:
    bool check(auto& s_freq, auto& t_freq){
        for(auto it:t_freq) if(s_freq[it.first]<it.second) return false;
        return true;
    }
    string minWindow(string s, string t) {
        int m=s.length(),n=t.length();
        if(m<n) return "";
        if(s==t) return s;
        string ans="";
        unordered_map<char,int> t_freq,s_freq;
        for(char c:t) t_freq[c]++;
        int left=0,right=0,len=INT_MAX;
        while(right<m) {
            s_freq[s[right]]++;
            while(left<right) {
                if(t_freq[s[left]]==0 || s_freq[s[left]]>t_freq[s[left]]) {
                    s_freq[s[left]]--;
                    left++;
                }
                else break;
            }
            if(check(s_freq,t_freq)) {
                if(len>right-left+1) {
                    len=right-left+1;
                    ans=s.substr(left,len);
                }
                s_freq[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};