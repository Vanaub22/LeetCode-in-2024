class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>> wRatio;
        for(int i=0;i<n;i++) wRatio.push_back({(double)wage[i]/quality[i],quality[i]});
        sort(wRatio.begin(),wRatio.end());
        priority_queue<int> pq;
        int sum=0;
        for(int i=0;i<k;i++) {
            pq.push(wRatio[i].second);
            sum+=wRatio[i].second;
        }
        double ans=wRatio[k-1].first*sum;
        for(int i=k;i<n;i++) {
            double dRatio=wRatio[i].first; // Paying this worker the minimum possible wage
            // Finding out the k smallest quality values
            if(!pq.empty() && pq.top()>wRatio[i].second) {
                sum+=wRatio[i].second-pq.top();
                pq.pop();
                pq.push(wRatio[i].second);                    
            }
            ans=min(ans,dRatio*sum);
        }
        return ans;
    }
};