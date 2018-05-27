class MinStack {
public:
    /** initialize your data structure here. */

	// use two stacks to access the smallest element in linear time
    stack<int> v;
    stack<int> smallest;
    MinStack() {
    }
    
    void push(int x) {
        v.push(x);
       if (smallest.empty() || x <= getMin()) smallest.push(x);
	   // if smallest is empty, then push the element into smallest
	   // else if the x is smallest than the current smallest element, then push the element into smallest
	   // In this way, x becomes the smallest element
    }
    
    void pop() {
        if (getMin() == v.top()) smallest.pop();  
		// if the current smallest element is equal to the top element of v
		// then pop the top element of the smallest
		// in this way, the next top element of smallest becomes smallest 
        v.pop();
    }
    
    int top() {
        return v.top();
    }
    
    int getMin() {
        return smallest.top();
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