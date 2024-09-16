// Bit Masking Approach (Use given hints)
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefXor=0,charMap[26]={0};
        charMap[0]=1,charMap[4]=2,charMap[8]=4,charMap[14]=8,charMap[20]=16;
        vector<int> prevIndex(32,-1);
        int ans=0;
        for(int i=0;i<s.length();i++) {
            prefXor^=charMap[s[i]-'a'];
            if(prevIndex[prefXor]==-1 && prefXor!=0) prevIndex[prefXor]=i;
            ans=max(ans,i-prevIndex[prefXor]);
        }
        return ans;
    }
};