class Solution {
public:
    // Sliding Window Approach 
    int numberOfSubstrings(string s) {
        unordered_map<char,int> sub_freq;
        int left,right=0,n=s.length(),cnt=0;
        for(;right<n;right++) {
            sub_freq[s[right]]++;
            while(sub_freq['a'] && sub_freq['b'] && sub_freq['c']) {
                cnt+=n-right; // Adding the rest of the substrings till the end
                sub_freq[s[left]]--; // Decreasing the length of the window
                left++;
            }
        }
        return cnt;
    }
};