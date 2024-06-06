class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k) return false;
        map<int,int> mp; // Will be using std::map as both Hashmap and Min-heap
        for(int i:nums) mp[i]++;
        while(!mp.empty()) {
            int gstart=(*mp.begin()).first;
            for(int i=gstart;i<gstart+k;i++) {
                if(mp.find(i)==mp.end()) return false;
                mp[i]--; // Using for this group
                if(mp[i]==0) {
                    if(i!=(*mp.begin()).first) return false;
                    mp.erase(i); // Exhausted after using in this group
                }
            }
        }
        return true;
    }
};