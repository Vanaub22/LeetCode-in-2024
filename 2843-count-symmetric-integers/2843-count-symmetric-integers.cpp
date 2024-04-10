class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int symm=0;
        for(int i=low;i<=high;i++) {
            string x=to_string(i);
            int n=x.size();
            if(n%2) continue;
            else {
                int h1=0,h2=0;
                for(int j=0;j<n;j++) {
                    if(j<n/2) h1+=x[j]-'0';
                    else h2+=x[j]-'0';
                }
                symm+=h1==h2;
            }
        }
        return symm;
    }
};