// Task scheduler question implemented with heap and a hash table (unordered_map)
class Solution {
public:


int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> freq;
    for(char task : tasks) {
        freq[task]++;
    }

    
    priority_queue<int> pq;
    for(auto [task, count] : freq) {
        pq.push(count);
    }

    int time = 0;

    while(!pq.empty()) {
        vector<int> temp; 
        int cycle = n + 1;  

        for(int i = 0; i < cycle; i++) {
            if(!pq.empty()) {
                temp.push_back(pq.top() - 1); 
                pq.pop();
            }
            time++;
            if(pq.empty() && 
            all_of(temp.begin(), temp.end(), 
            [](int x){return x==0;}))
                break; 
        }

        
        for(int c : temp) {
            if(c > 0) pq.push(c);
        }
    }

    return time;
}

};