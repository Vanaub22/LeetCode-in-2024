class Solution {
private:
    // Checking if string a is a subsequence of string b
    bool check(auto& a, auto& b) {
        if(a.size()>b.size()) return false;
        int i=0;
        for(char c:b) if(a[i]==c) i++;
        return a.size()==i;
    }
public:
    int findLUSlength(auto& x) {
        int n=x.size(),lus=-1;
        for(int i=0;i<n;i++) {
            bool isSubseq=false;
            for(int j=0;j<n;j++) if(i!=j && check(x[i],x[j])) {
                isSubseq=true;
                break;
            }
            if(!isSubseq) lus=max(lus,(int)x[i].size());
        }
        return lus;
    }
};