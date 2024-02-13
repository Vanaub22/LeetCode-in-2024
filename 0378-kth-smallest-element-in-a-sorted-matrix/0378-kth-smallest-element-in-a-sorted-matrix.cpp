class Solution {
private:
    int lessThanOrEqual(int mid, auto& matrix, int n) {
        int r=0,c=n-1,cnt=0;
        while(r>=0 && r<n && c>=0 && c<n) {
            if(matrix[r][c]<=mid) {
                cnt+=c+1;
                r++;
            }
            else c--;
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),smallest=matrix[0][0],largest=matrix[n-1][n-1];
        while(smallest!=largest) {
            int mid=smallest+(largest-smallest)/2;
            if(lessThanOrEqual(mid,matrix,n)<k) smallest=mid+1;
            else largest=mid;
        }
        return smallest;
    }
};