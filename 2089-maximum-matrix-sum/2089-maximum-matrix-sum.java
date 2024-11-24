class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long ans=0;
        int m=matrix.length,n=matrix[0].length,neg=0,minAbsVal=Integer.MAX_VALUE;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]<0) neg++;
                minAbsVal=Math.min(minAbsVal,Math.abs(matrix[i][j]));
                ans+=Math.abs(matrix[i][j]);
            }
        }
        return neg%2==0?ans:ans-2*minAbsVal;
    }
}