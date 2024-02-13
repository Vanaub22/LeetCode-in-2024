// Will be using prefix sum to reduce query answer fetch time complexity to O(1)
class Solution {
private:
    bool isVString(string& s) {
        return isVowel(s[0]) && isVowel(s.back());
    }
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m=queries.size(),n=words.size();
        vector<int> answer(m);
        int pref[n];
        memset(pref,0,n);
        pref[0]=isVString(words[0])?1:0;
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+isVString(words[i]);
        for(int i=0;i<m;i++) {
            int ll=queries[i][0],ul=queries[i][1];
            if(!ll) answer[i]=pref[ul];
            else answer[i]=pref[ul]-pref[ll-1];
        }
        return answer;
    }
};