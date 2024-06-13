class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int moves=0;
        sort(students.begin(),students.end());
        sort(seats.begin(),seats.end());
        for(int i=0;i<seats.size();i++) moves+=abs(seats[i]-students[i]);
        return moves;
    }
};