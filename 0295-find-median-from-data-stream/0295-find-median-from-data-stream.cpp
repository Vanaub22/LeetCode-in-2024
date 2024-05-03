class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> greater_pq; // Min Heap
    priority_queue<int> lesser_pq; // Max Heap
    
    void addNum(int x) {
        int m=lesser_pq.size(),n=greater_pq.size(); // Difference in sizes will be 1 at most
        if(m>n) {
            if(lesser_pq.top()>x) {
                greater_pq.push(lesser_pq.top());
                lesser_pq.pop();
                lesser_pq.push(x);
            }
            else greater_pq.push(x);
        }
        else if(m<n) {
            if(greater_pq.top()<x) {
                lesser_pq.push(greater_pq.top());
                greater_pq.pop();
                greater_pq.push(x);
            }
            else lesser_pq.push(x);
        }
        else {
            if(!m) lesser_pq.push(x);
            else if(!n) greater_pq.push(x);
            else if(lesser_pq.top()<x) greater_pq.push(x);
            else lesser_pq.push(x);
        }
    }
    
    double findMedian() {
        int m=lesser_pq.size(),n=greater_pq.size();
        if(!m && !n) return 0;
        else if(m>n) return lesser_pq.top();
        else if(m<n) return greater_pq.top();
        else return (lesser_pq.top()+greater_pq.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */