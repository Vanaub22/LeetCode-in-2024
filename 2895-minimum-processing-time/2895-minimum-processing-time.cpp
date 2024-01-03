class Solution {
public:
    int minProcessingTime(vector<int>& pTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end(),greater<int>());
        sort(pTime.begin(),pTime.end());
        int n=pTime.size(),time=-1;
        // Assigning the longest tasks to the processor which becomes available first
        for(int i=0;i<n;i++) for(int j=i*4;j<=i*4+3;j++) time=max(time,pTime[i]+tasks[j]);
        return time;
    }
};