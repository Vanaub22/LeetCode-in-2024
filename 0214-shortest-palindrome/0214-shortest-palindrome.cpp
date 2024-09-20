class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        if(!n) return s;
        // Finding the longest Palindromic prefix
        int left=0;
        for(int right=n-1;right>=0;right--) if(s[left]==s[right]) left++;
        if(left==n) return s; // The string is already a palindrome
        string nonPalindromeSuffix=s.substr(left);
        return string(nonPalindromeSuffix.rbegin(),nonPalindromeSuffix.rend())+shortestPalindrome(s.substr(0,left))+nonPalindromeSuffix;
    }
};