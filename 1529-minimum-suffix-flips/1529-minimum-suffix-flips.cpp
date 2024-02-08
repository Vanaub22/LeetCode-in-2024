class Solution {
public:
    int minFlips(string target) {
        int ops=0;
        bool one=false;
        for(int i=0;i<target.size();i++) {
            if(one) {
                if(target[i]=='0') {
                    one=false;
                    ops++;
                } 
            }
            else {
                if(target[i]=='1') {
                    one=true;
                    ops++;
                }
            }
        }
        return ops;  
    }
};