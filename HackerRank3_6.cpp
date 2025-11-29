// RoadsandLibraries lines(6-39)
#include <bits/stdc++.h>

using namespace std;

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if(c_road >= c_lib) return (long)n * c_lib;

    vector<vector<int>> graph(n + 1);
    for(auto &edge : cities) {
        int from = edge[0];
        int to = edge[1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<bool> visited(n + 1, false);
    long totalCost = 0;

    function<long(int)> visit = [&](int current) -> long {
        visited[current] = true;
        long componentCount = 1;
        for(int neighbor : graph[current]) {
            if(!visited[neighbor]) {
                componentCount += visit(neighbor);
            }
        }
        return componentCount;
    };

    for(int city = 1; city <= n; city++) {
        if(!visited[city]) {
            long componentSize = visit(city);
            totalCost += c_lib + (componentSize - 1) * (long)c_road;
        }
    }

    return totalCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(q_temp);

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input;
        stringstream ss(first_multiple_input_temp);
        string temp;
        while(ss >> temp) first_multiple_input.push_back(temp);

        int n = stoi(first_multiple_input[0]);
        int m = stoi(first_multiple_input[1]);
        int c_lib = stoi(first_multiple_input[2]);
        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m, vector<int>(2));
        for(int i = 0; i < m; i++) {
            string line;
            getline(cin, line);
            stringstream ss2(line);
            ss2 >> cities[i][0] >> cities[i][1];
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        fout << result << "\n";
    }

    fout.close();
    return 0;
}
