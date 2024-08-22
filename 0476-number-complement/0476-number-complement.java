class Solution {
    public int findComplement(int num) {
        int exp=0,complement=0;
        while(num!=0) {
            int bit=num&1;
            if(bit==0) complement+=Math.pow(2,exp);
            exp++;
            num>>=1;
        }
        return complement;
    }
}