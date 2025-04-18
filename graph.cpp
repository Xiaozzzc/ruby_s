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
