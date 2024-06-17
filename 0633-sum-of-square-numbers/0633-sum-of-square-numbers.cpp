class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int low=0,high=sqrt(c),x;
        while(low<=high) {
            x=low*low+high*high;
            if(x==c) return true;
            else if(x>c) high--;
            else low++;
        }
        return false;
    }
};