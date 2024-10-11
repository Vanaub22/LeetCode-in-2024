class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        auto timing=times[targetFriend];
        sort(times.begin(),times.end());
        vector<int> chairOccupied(n);
        for(auto& time:times) {
            for(int i=0;i<n;i++) {
                if(chairOccupied[i]<=time[0]) {
                    chairOccupied[i]=time[1];
                    if(time==timing) return i;
                    break;
                }
            }
        }
        return 0;
    }
};