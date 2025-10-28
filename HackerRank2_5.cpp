// Queues implemented using two stacks
// **imp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class myQueue
{
    private:
     stack<int> instack;
     stack<int> outstack;
    public:
      void enqueue(int x)
      {
        instack.push(x);
      }
      void dequeue()
      {
        if(outstack.empty())
        {
            while(!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
            
        }
        outstack.pop();
      }
      void print(){
      if(outstack.empty())
        {
            while(!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
        }
        cout << outstack.top() << endl;
    }
     
    
    
    
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    myQueue q;
    int queries;
    int n,val;
    cin>>queries;
    for(int i=0; i<queries;i++)
    {
        cin>>n;
        if(n==1)
        {
            cin>>val;
            q.enqueue(val);
            
            
        }
        else if(n==2)
        {
            q.dequeue();
        }
        else if(n==3)
        {
            q.print();
        }
    }
    return 0;
}
