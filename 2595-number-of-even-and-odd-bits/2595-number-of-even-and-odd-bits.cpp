class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0,odd=0,i=0;
        while(n) {
            if(n%2) {
                even+=i%2==0;
                odd+=i%2;
            }
            n/=2;
            i++;
        }
        return {even,odd};
    }
};