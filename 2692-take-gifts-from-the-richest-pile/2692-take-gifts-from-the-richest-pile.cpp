class Solution {
public:
    long long pickGifts(vector<int>& gift_piles, int k) {
        priority_queue<int> pq;
        for(int gift_pile:gift_piles) pq.push(gift_pile);
        for(int i=0;i<k;i++) {
            if(pq.empty()) return 0;
            pq.push(sqrt(pq.top()));
            pq.pop();
        }
        long long gifts=0;
        while(!pq.empty()) {
            gifts+=pq.top();
            pq.pop();
        }
        return gifts;
    }
};