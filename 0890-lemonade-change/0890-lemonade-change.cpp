class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> notes={{5,0},{10,0},{20,0}};
        for(int bill:bills) {
            notes[bill]++;
            if(bill==10) {
                if(notes[5]) notes[5]--;
                else return false;
            }
            else if(bill==20) {
                if(notes[10] && notes[5]) notes[10]--,notes[5]--;
                else if(notes[5]>=3) notes[5]-=3;
                else return false;
            }
        }
        return true;
    }
};