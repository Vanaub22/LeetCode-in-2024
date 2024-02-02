class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        while(n) {
            // We cannot use char directly for c because char is 8 bits in size
            // It might overflow and show incorrect characters due to large negative values
            int c='a'+25-((n*26)-k);
            if(c<'a') c='a';
            ans+=(char)c;
            k-=c-'a'+1;
            n--;
        }
        return ans;
    }
};