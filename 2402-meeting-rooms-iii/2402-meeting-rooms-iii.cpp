#define lli long long int
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        set<pair<lli,int>> occupied; // std::pair elements store (finish time, room no.)
        set<int> available; // To store available rooms in ascending order of room numbers
        vector<int> used(n,0);
        for(int room=0;room<n;room++) available.insert(room);
        for(auto& meeting:meetings) {
            // Releasing previously occupied rooms on completion of scheduled meetings
            while(!occupied.empty() && occupied.begin()->first<=meeting[0]) {
                int rno=occupied.begin()->second;
                available.insert(rno);
                occupied.erase(occupied.begin());
            }
            if(available.empty()) {
                // Meeting will be delayed
                int rno=occupied.begin()->second;
                lli ftime=occupied.begin()->first+meeting[1]-meeting[0];
                occupied.erase(occupied.begin());
                occupied.insert(make_pair(ftime,rno));
                used[rno]++;
            }
            else {
                // Rooms are available => Meeting will be scheduled immediately
                int rno=*available.begin();
                available.erase(available.begin());
                occupied.insert(make_pair(meeting[1],rno));
                used[rno]++;
            }
        }
        return max_element(used.begin(),used.end())-used.begin(); // To return the room number
    }
};