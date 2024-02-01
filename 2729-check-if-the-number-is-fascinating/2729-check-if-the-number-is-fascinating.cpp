class Solution {
public:
    bool isFascinating(int n) {
        string s=to_string(n)+to_string(n*2)+to_string(n*3);
        int check[10]={0};
        for(char c:s) {
            if(c=='0' || check[c-'0']) return false;
            check[c-'0']++;
        }
        return true;
    }
};