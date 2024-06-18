class Solution {
private:
    struct Job {
        int prof,diff;
    };
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size(),maxprof=0;
        vector<Job> jobs(n);
        for(int i=0;i<n;i++) jobs[i].prof=profit[i],jobs[i].diff=difficulty[i];
        sort(jobs.begin(),jobs.end(),[&](Job& a, Job& b) {
            return a.prof==b.prof?a.diff<b.diff:a.prof>b.prof;
        });
        for(int w:worker) {
            for(int i=0;i<n;i++) if(jobs[i].diff<=w) {
                maxprof+=jobs[i].prof;
                break;
            }
        }
        return maxprof;        
    }
};