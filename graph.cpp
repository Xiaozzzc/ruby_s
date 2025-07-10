#include "dfs.cpp"
#include "linkedLst.cpp"
// #include "utils.cpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;


class graph {
public:
    /***
     * Ways to store a graph
     *
     * Adjacency Matrix
     * matrix[i][j] == 1 if node i, j is connected, otherwise 0
     *
     * Adjacency List
     * graph = {
     *   'A': ['B', 'C'],
     *   'B': ['A', 'D'],
     *   'C': ['A'],
     *   'D': ['B']
     * }
     *
     */
    // 2101. Detonate the Maximum Bombs
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n, vector<int>()); // graph[i][j] == 1 means nodes i and j are connected
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (connected(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2])) {
                    graph[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> visited(n);
            int t = dfs(graph, visited, i);
            ans = max(ans, t);
        }
        return ans;
    }

    // "vector<vector<int>>& graph", '&' is a must, to avoid repeatedly creating objects
    int dfs(vector<vector<int>>& graph, vector<int>& visited, int cur) {
        visited[cur] = 1;
        int t = 1;
        for (int next : graph[cur]) {
            if (visited[next] == 1) {
                continue;
            }
            t += dfs(graph, visited, next);
        }
        return t;
    }

    bool connected(int x1, int y1, int x2, int y2, long r1) {
        long x12 = pow(x1 - x2, 2);
        long y12 = pow(y1 - y2, 2);
        return x12 + y12 <= r1 * r1;
    }

    // citadel interview question 2
    // user with the most common friends is the recommended friend, if there are more than one, pick the one with the smallest id
    // given n users, and their friendships, find out each person's recommended friend
    // e.g.
    // n = 5, friendships = [[0,1],[1,2],[1,3],[2,3],[3,4]]
    // -> [3, 2, 1, 0, 1]
    // n = 3, friendships = [[0,1],[1,2],[0,2]]
    // -> [-1, -1, -1]
    vector<int> getRecommendedFriends(int n, vector<vector<int>>& friendships) {
        vector<set<int>> sets(n); // set[i] is the friend set for ith user
        for (auto& f : friendships) {
            int m = f[0];
            int n = f[1];
            sets[m].insert(n);
            sets[n].insert(m);
        }

        vector<int> ans(n, -1); // ans[i] is the final recommended user for user i
        // for each user
        for (int cur = 0; cur < n; ++cur) {
            unordered_map<int, int> mp; // mp[i] is the common friends number between user cur and i
            for (int frd : sets[cur]) {
                // friend of cur
                for (int ffrd : sets[frd]) {
                    // friend of "friend of cur"
                    if (ffrd == cur) {
                        continue;
                    }
                    if (sets[cur].count(ffrd)) {
                        // it's already friend, skip
                        continue;
                    }
                    mp[ffrd]++;
                }
            }

            int maxId = -1; // best match user id
            int maxNum = 0; // common friend num
            for (auto& p : mp) {
                int i = p.first; // ith user
                int num = p.second; // common friends num
                if (num > maxNum || (num == maxNum && (maxId == -1 || i < maxId))) {
                    maxId = i;
                    maxNum = num;
                }
            }
            if (sets[cur].count(maxId)) {
                maxId = -1;
            }
            ans[cur] = maxId;
        }
        return ans;
    }

    // 2050. Parallel Courses III
    // there are n courses, and some courses need to be done first in order to do the next,
    // each course costs certain amount of time to complete, you can do multiple courses at same time
    // return the minimum time you can complete all courses.
    //
    // Topology Traverse
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> in(n); // in-degree of each element
        vector<vector<int>> adj(n, vector<int>()); // adjacency matrix, adj[1] = [3,4,6] means node 1 points to [3,4,6]
        for (int i = 0; i < relations.size(); i++) {
            in[relations[i][1] - 1]++;
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        vector<int> start(n);
        int ans = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            vector<int> curNext = adj[cur];
            for (int idx : curNext) {
                in[idx]--;
                start[idx] = max(start[idx], start[cur] + time[cur]); // but here
                if (in[idx] == 0) {
                    q.push(idx);
                    // start[idx] = max(start[idx], start[cur] + time[cur]);  // not here
                    // ans = max(ans, start[idx] + time[idx]);  // not here
                }
            }
            ans = max(ans, start[cur] + time[cur]); // but here
        }
        return ans;
    }
};
