// Minstack class implemented using two stacks getmin function returns the min value O(1)

class MinStack {
private:
    stack<int>s;
    stack<int>minstack;    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minstack.empty()|| val<=minstack.top())
        {
            minstack.push(val);
        }
        
    }
    
    void pop() {
        if(s.empty())
        {
            return;
        }
        if(s.top()==minstack.top())
        {
            minstack.pop();
        }
        s.pop();
        
    }
    
    int top() {
        return s.top();
        
    }
    
    int getMin() {
       return minstack.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */