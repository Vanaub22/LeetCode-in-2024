/*
    Using trick from hint:
    Each beautiful substring is of even length.
    Therefore, each substring of length 2 inside such beautiful substrings will be beautiful individually
*/
class Solution {
    public int minChanges(String s) {
        int n=s.length(),changes=0;
        for(int i=0;i<n-1;i+=2) if(s.charAt(i)!=s.charAt(i+1)) changes++;
        return changes;
    }
}