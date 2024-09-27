class MyCalendarTwo {
private:
    bool checkOverlap(int s1, int e1, int s2, int e2) {
        return max(s1,s2)<min(e1,e2);
    }
    auto findOverlap(int s1, int e1, int s2, int e2) {
        return make_pair(max(s1,s2),min(e1,e2));
    }
public:
    vector<pair<int,int>> sBooking,dBooking;
    bool book(int start, int end) {
        for(auto& [s,e]:dBooking) if(checkOverlap(start,end,s,e)) return false;
        for(auto& [s,e]:sBooking) if(checkOverlap(start,end,s,e)) dBooking.emplace_back(findOverlap(start,end,s,e));
        sBooking.emplace_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */