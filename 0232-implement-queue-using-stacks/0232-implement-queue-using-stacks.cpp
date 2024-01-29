class MyQueue {
public:
    stack<int> stk;
    void push(int x) {
        stk.push(x);
    }
    int pop() {
        stack<int> s;
        while(!stk.empty()){
            s.push(stk.top());
            stk.pop();
        }
        int popped=s.top();
        s.pop();
        while(!s.empty()){
            stk.push(s.top());
            s.pop();
        }
        return popped;
    }
    int peek() {
        stack<int> s=stk;
        int front;
        while(!s.empty()) {
            front=s.top();
            s.pop();
        }
        return front;
    }
    bool empty() {
        return stk.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */