// Network Delay Time problem
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& timesList, int nNodes, int start) {
        vector<vector<pair<int,int>>> adjList(nNodes + 1);
        for(auto &edge : timesList) {
            int from = edge[0], to = edge[1], weight = edge[2];
            adjList[from].push_back({to, weight});
        }

        const int INF = 1e9;
        vector<int> minTime(nNodes + 1, INF);
        minTime[start] = 0;

        using pii = pair<int,int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, start});

        while(!pq.empty()) {
            auto [currTime, currNode] = pq.top(); pq.pop();
            if(currTime > minTime[currNode]) continue;

            for(auto &[nextNode, edgeTime] : adjList[currNode]) {
                if(minTime[currNode] + edgeTime < minTime[nextNode]) {
                    minTime[nextNode] = minTime[currNode] + edgeTime;
                    pq.push({minTime[nextNode], nextNode});
                }
            }
        }

        int maxDelay = 0;
        for(int i = 1; i <= nNodes; i++) {
            if(minTime[i] == INF) return -1;
            maxDelay = max(maxDelay, minTime[i]);
        }

        return maxDelay;
    }
};
