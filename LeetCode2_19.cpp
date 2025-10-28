// ReorganizeString question (max heap)
class Solution {
public:


 string reorganizeString(string s) {
    unordered_map<char,int> freq;
    for(char c : s) freq[c]++;

    priority_queue<pair<int,char>> maxHeap;
    for(auto [c, count] : freq) {
        maxHeap.push({count, c});
    }

    string result = "";

    while(maxHeap.size() > 1) {
        auto [count1, char1] = maxHeap.top(); 
        maxHeap.pop();
        auto [count2, char2] = maxHeap.top(); 
        maxHeap.pop();

        result += char1;
        result += char2;

        if(count1 > 1) 
        maxHeap.push({count1 - 1, char1});
        if(count2 > 1) 
        maxHeap.push({count2 - 1, char2});
    }

    if(!maxHeap.empty()) {
        if(maxHeap.top().first > 1) return "";
        result += maxHeap.top().second;
    }

    return result;
}


};