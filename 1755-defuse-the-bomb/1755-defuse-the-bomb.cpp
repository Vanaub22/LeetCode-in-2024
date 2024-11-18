class Solution {
public:
    vector<int> decrypt(vector<int> code, int k) {
        int n=code.size();
        vector<int> ans(n,0);
        if(!k) return ans;
        else {
            for(int i=0;i<n;i++) {
                int j=1,x=0;
                if(k>0) {
                    while(j<=k) {
                        x+=code[(i+j)%n];
                        j++;
                    }
                }
                else {
                    while(j<=abs(k)) {
                        if(i-j>=0) x+=code[i-j];
                        else x+=code[n+i-j];
                        j++;
                    }
                }
                ans[i]=x;
            }
        }
        return ans;
    }
};