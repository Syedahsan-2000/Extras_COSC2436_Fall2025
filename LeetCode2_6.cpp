// dailyTemperature question using stacks
// Review once

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
    vector<int> res(n, 0);
    stack<int> st;  // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temps[i]
                 > temps[st.top()]) {
            int idx = st.top();
            st.pop();
            res[idx] = i - idx;
        }
        st.push(i);
    }
    return res;
        
    }
};