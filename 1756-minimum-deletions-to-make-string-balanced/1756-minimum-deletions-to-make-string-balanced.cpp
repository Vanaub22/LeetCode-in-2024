// Not the most optimized approach
// T.C. O(N) S.C. O(N)
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size(),right_a[n],left_b[n],a=0,b=0,ans=n;
        // right_a[i] will store the no. of a's to the right of index i
        // left_b[i] will store the store the no. of b's to the left of index i
        for(int i=0;i<n;i++) {
            left_b[i]=b;
            if(s[i]=='b') b++;
        }
        for(int i=n-1;i>=0;i--) {
            right_a[i]=a;
            if(s[i]=='a') a++;
        }
        // If index i is partition pt. then we have to delete all a's to the right of i and all b's to the left of i
        for(int i=0;i<n;i++) ans=min(ans,right_a[i]+left_b[i]);
        return ans;
    }
};