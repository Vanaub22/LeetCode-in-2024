class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto& word:words) {
            int n=word.size();
            bool palindromic=true;
            for(int i=0;i<n/2;i++) if(word[i]!=word[n-i-1]) {
                palindromic=false;
                break;
            }
            if(palindromic) return word;
        }
        return "";
    }
};