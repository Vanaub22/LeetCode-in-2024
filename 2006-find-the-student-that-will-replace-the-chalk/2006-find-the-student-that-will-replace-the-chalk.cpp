class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size(),i=0;
        long long s=0;
        for(int c:chalk) s+=c;
        k%=s;
        for(;;) {
            if(k-chalk[i]<0) break;
            else {
                k-=chalk[i];
                i++;
                i%=n;
            }
        }
        return i;
    }
};