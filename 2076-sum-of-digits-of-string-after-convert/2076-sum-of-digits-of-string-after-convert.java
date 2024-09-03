class Solution {
    public int getLucky(String s, int k) {
        String x="";
        for(int i=0;i<s.length();i++) x+=Integer.toString(s.charAt(i)-'a'+1);
        System.out.println(x);
        int sum=0;
        for(int i=0;i<k;i++) {
            sum=0;
            for(int j=0;j<x.length();j++) sum+=x.charAt(j)-'0';
            x=Integer.toString(sum);
        }
        return sum;
    }
}