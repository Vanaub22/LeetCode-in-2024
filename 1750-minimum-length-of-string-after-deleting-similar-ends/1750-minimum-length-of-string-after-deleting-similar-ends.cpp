class Solution {
public:
    int minimumLength(string s) {
        int start=0,end=s.length()-1;
        while(start<end)
        if(s[start]==s[end]){
            char c=s[start];
            while(start<=end && s[start]==c) start++;
            while(end>=start && s[end]==c) end--;
        }
        else break;
        return end-start+1;
    }
};