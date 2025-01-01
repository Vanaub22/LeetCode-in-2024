class Solution {
    public int maxScore(String s) {
        int n=s.length(),suff_ones=0,pref_zeroes=0,score;
        for(int i=0;i<n;i++) if(s.charAt(i)=='1') suff_ones++;
        if(s.charAt(0)=='0') pref_zeroes++;
        else suff_ones--;
        score=pref_zeroes+suff_ones;
        for(int i=1;i<n-1;i++) {
            if(s.charAt(i)=='1') suff_ones--;
            else pref_zeroes++;
            score=Math.max(score,suff_ones+pref_zeroes);
        }
        return score;
    }
}