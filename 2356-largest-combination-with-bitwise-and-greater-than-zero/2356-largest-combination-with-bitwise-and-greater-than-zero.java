class Solution {
    public int largestCombination(int[] candidates) {
        int ans=0;
        for(int i=0;i<24;i++) {
            int ith_bit_set=0;
            for(int candidate:candidates) ith_bit_set+=candidate>>i&1;
            ans=Math.max(ans,ith_bit_set);
        }
        return ans;
    }
}