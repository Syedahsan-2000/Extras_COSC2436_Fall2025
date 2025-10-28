// implementing myQueue class using two stacks lines 2-48
// **imp
class MyQueue {
private:
   stack<int> instack;
   stack<int> outstack;    
public:
    MyQueue() {}
        
    
    void push(int x) {
        instack.push(x);

        
    }
    
    int pop() {
        if(outstack.empty())
        {
            while(!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
        }
        int value=outstack.top();
        outstack.pop();
        return value;
        
    }
    
    int peek() {
        if(outstack.empty())
        {
            while(!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
        }
        return outstack.top();
        
    }
    
    bool empty() {
        return instack.empty() && outstack.empty();
        
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