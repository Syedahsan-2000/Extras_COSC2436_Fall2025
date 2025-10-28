// isValid paranthesis returning a bool implemented using stack line 4-37
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size();i++)
        {
            if(s.at(i)=='('|| s.at(i)=='{' || 
            s.at(i)=='[')
            {
               st.push(s.at(i)); 
            }
            if(s.at(i)==')'|| s.at(i)=='}' || 
            s.at(i)==']')
            {
                if(st.empty()) return false;
                if(s.at(i)==')' && st.top()!='('|| 
                s.at(i)=='}' && st.top()!='{' 
                || s.at(i)==']' && st.top()!='[')
                {
                    return false;
                }
                st.pop();
            }
            
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};