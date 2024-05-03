class Solution {
public:
    int compareVersion(string& v1, string& v2) {
        int i=0,j=0,l1=v1.length(),l2=v2.length();
        while(true) {
            long long int r1=0,r2=0;
            while(i<l1 && v1[i]!='.') {
                r1=r1*10+v1[i]-'0';
                i++;
            }
            while(j<l2 && v2[j]!='.') {
                r2=r2*10+v2[j]-'0';
                j++;
            }
            if(r1<r2) return -1;
            else if(r1>r2) return 1;
            if(i>=l1 && j>=l2) break;
            i++,j++;
        }
        return 0;
    }
};