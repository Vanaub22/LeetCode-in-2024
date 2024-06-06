class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize) return false;
        map<int,int> mp;
        for(int i:hand) mp[i]++;
        while(!mp.empty()) {
            int groupStart=(*mp.begin()).first;
            for(int i=groupStart;i<groupStart+groupSize;i++) {
                if(mp.find(i)==mp.end()) return false;
                mp[i]--;
                if(!mp[i]) {
                    if(i!=(*mp.begin()).first) return false;
                    mp.erase(i);
                }
            }
        }
        return true;
    }
};