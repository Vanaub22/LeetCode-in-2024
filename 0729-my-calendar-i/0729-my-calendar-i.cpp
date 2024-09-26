class MyCalendar {
public:
    vector<pair<int,int>> intervals;
    bool book(int start, int end) {
        for(auto [s,e]:intervals) if(start<e && s<end) return false;
        intervals.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */