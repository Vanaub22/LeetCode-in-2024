class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long score=0;
        for(int i:nums) pq.push(i);
        for(int i=0;i<k;i++){
            if(pq.empty()) return score;
            score+=pq.top();
            pq.push(ceil((double)pq.top()/3));
            pq.pop();
        }
        return score;
    }
};