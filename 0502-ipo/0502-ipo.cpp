class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size(),i=0;
        vector<pair<int,int>> projects;
        for(int i=0;i<capital.size();i++) projects.push_back({capital[i],profits[i]});
        sort(projects.begin(),projects.end(),[&](auto& a, auto& b) {
            return a.first==b.first?a.second>b.second:a.first<b.first;
        });
        priority_queue<int> pq; // Max Heap to accept projects with highest profit proposition
        while(k--) {
            // Projects that can be undertaken with current capital
            while(i<n && projects[i].first<=w) {
                pq.push(projects[i].second);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top(); // Adding profit to current capital
            pq.pop();
        }
        return w;
    }
};