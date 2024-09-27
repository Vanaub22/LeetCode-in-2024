class MyCalendarTwo {
public:
    vector<pair<int,int>> sBooking,dBooking;
    bool book(int start, int end) {
        for(auto& [s,e]:dBooking) if(max(start,s)<min(end,e)) return false;
        for(auto& [s,e]:sBooking) if(max(start,s)<min(end,e)) dBooking.emplace_back(make_pair(max(start,s),min(end,e)));
        sBooking.emplace_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */