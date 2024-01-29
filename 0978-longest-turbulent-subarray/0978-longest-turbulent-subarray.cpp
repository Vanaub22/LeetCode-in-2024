class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++) {
            int w_end=i,comp=-1; // -1 => Not assigned
            while(w_end<arr.size()) {
                if(w_end-i!=0) {
                    if(arr[w_end-1]==arr[w_end]) break;
                    else if(arr[w_end-1]>arr[w_end]) {
                        if(comp==0) break;
                        else comp=0;
                    }
                    else {
                        if(comp==1) break;
                        comp=1;
                    }
                }
                ans=max(ans,w_end-i+1);
                w_end++;
            }
        }
        return ans;
    }
};