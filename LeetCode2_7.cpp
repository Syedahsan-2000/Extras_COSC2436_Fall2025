// postfix using stacks (Reverse polish notation)
// **imp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token: tokens)
        {
            if(token=="+" || token=="-" 
            || token=="*"|| token=="/")
            {
                int b=s.top(); s.pop();
                int a=s.top(); s.pop();
                int result;
                if(token=="+")
                {
                    result=a+b;
                }
                else if(token=="-")
                {
                    result=a-b;
                }
                else if(token=="*")
                {
                    result=a*b;
                }
                else if(token=="/")
                {
                    result=a/b;
                }
                s.push(result);

            }
            else{
            s.push(stoi(token));}
        }
        return s.top();
        
    }
};