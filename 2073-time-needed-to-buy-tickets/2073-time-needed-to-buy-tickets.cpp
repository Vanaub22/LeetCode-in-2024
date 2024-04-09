class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size(),t=0;
        while(tickets[k]) {
            for(int i=0;i<n;i++) {
                if(tickets[i]) {
                    tickets[i]--;
                    t++;
                    if(i==k && !tickets[i]) return t;
                }
            }
        }
        return -1;
    }
};