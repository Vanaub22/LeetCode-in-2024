class Solution {
    public int reverse(int x) {
        long revx=0;
        boolean negative=false;
        if(x<0) {
            x=Math.abs(x);
            negative=true;
        }
        while(x>0) {
            revx=revx*10+x%10;
            if(!negative && revx>Integer.MAX_VALUE || revx*(-1)<Integer.MIN_VALUE) return 0;
            x/=10;
        }
        return negative?(-1)*(int)revx:(int)revx;
    }
}