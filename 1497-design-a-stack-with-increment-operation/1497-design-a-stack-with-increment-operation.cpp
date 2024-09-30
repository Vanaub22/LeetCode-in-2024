class CustomStack {
public:
    int capacity,top,*stk;
    CustomStack(int maxSize) {
        top=-1;
        capacity=maxSize;
        stk=new int[capacity];
    }
    
    void push(int x) {
        if(top==capacity-1) return;
        stk[++top]=x;
    }
    
    int pop() {
        if(top==-1) return -1;
        int popped=stk[top];
        stk[top--]=-1;
        return popped;
    }
    
    void increment(int k, int val) {
        int idx=0;
        while(idx<=k-1 && idx<=top) stk[idx++]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */