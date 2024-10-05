class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        // Using vectors so that they can be compared using overloaded '==' operator
        vector<int> freq(26,0),w_freq(26,0);
        for(char c:s1) freq[c-'a']++;
        int n=s2.length(),left=0,right=s1.length()-1;
        for(int i=left;i<=right;i++) w_freq[s2[i]-'a']++;
        while(right<n) {
            if(freq==w_freq) return true;
            else {
                right++;
                if(right>n-1) break;
                else w_freq[s2[right]-'a']++;
                w_freq[s2[left++]-'a']--;
            }
        }
        return false;
    }
};