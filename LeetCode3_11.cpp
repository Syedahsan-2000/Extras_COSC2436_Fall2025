// Course Schedule Problem
class Solution {
public:
    bool canFinish(int totalCourses, vector<vector<int>>& prereqPairs) {
        vector<vector<int>> adjList(totalCourses);
        for(auto &pair : prereqPairs) {
            int course = pair[0];
            int prereq = pair[1];
            adjList[prereq].push_back(course);
        }

        vector<int> state(totalCourses, 0); 

        function<bool(int)> detectCycle = [&](int node) -> bool {
            if(state[node] == 1) return false;
            if(state[node] == 2) return true;

            state[node] = 1;
            for(int nextCourse : adjList[node]) {
                if(!detectCycle(nextCourse)) return false;
            }
            state[node] = 2;
            return true;
        };

        for(int i = 0; i < totalCourses; i++) {
            if(state[i] == 0) {
                if(!detectCycle(i)) return false;
            }
        }
        return true;
    }
};
