class Solution {
public:
    bool checkPowersOfThree(int n) {
        // From constraints: Maximum permissible power of 3 is 16, i.e. 3^16
        return helper(n,16);
    }
    // Helper fn. to check recursively
    bool helper(int n, int exp) {
        if(!n) return true;
        for(int i=exp;i>=0;i--) {
            int p=pow(3,i);
            if(n-p>=0 && helper(n-p,i-1)) return true;
        }
        return false;
    }
};