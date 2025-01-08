class Solution {
private:
    bool isPrefixAndSuffix(string a, string b) {
        int m=a.length(),n=b.length();
        return b.substr(0,m)==a && b.substr(n-m)==a;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(),ans=0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(isPrefixAndSuffix(words[i],words[j])) ans++;
            }
        }
        return ans;
    }
};