class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char task:tasks) freq[task]++;
        int fmax=INT_MIN,nmax=0;
        for(auto f:freq) fmax=max(fmax,f.second);
        for(auto f:freq) if(f.second==fmax) nmax++;
        return max((fmax-1)*(n+1)+nmax,(int)tasks.size());
    }
};