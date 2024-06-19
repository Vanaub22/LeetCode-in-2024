class Solution {
private:
    int possibleBouquets(int d, auto& b, int k) {
        int adj=0,ans=0,n=b.size();
        for(int i=0;i<n;i++) {
            if(b[i]<=d) adj++;
            if(b[i]>d || i==n-1) {
                ans+=adj/k;
                adj=0;
            }
        }
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1,mid,n=bloomDay.size(),left=0,right=*max_element(bloomDay.begin(),bloomDay.end());
        while(left<=right) {
            mid=left+(right-left)/2;
            if(possibleBouquets(mid,bloomDay,k)>=m) {
                right=mid-1;
                ans=mid;
            }
            else left=mid+1;   
        }     
        return ans;
    }
};