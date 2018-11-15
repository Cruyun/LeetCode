class MinStack {
private:
    vector<long> s;
    long min_val = INT_MAX;
public: 
    void push(int x) {
        long d = x - min_val;
        min_val = x < min_val ? x : min_val;
        s.push_back(d);
    }
    
    void pop() {
        long d = s.back();
        if (d < 0) min_val -= d;
        s.pop_back();
    }
    
    int top() {
        long d = s.back();
        return d <= 0 ? min_val : min_val + d;
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */