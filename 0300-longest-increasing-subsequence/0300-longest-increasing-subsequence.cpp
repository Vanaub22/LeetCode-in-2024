class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subseq;
        for(int i:nums){
            int n=subseq.size();
            if(n==0 || subseq[n-1]<i) subseq.push_back(i);
            else {
                for(int j=0;j<n;j++) if(subseq[j]>=i){
                    subseq[j]=i;
                    break;
                }
            }
        }
        return subseq.size();
    }
};