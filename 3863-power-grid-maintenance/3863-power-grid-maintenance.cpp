#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, rankv;
    DSU(int n): n(n), parent(n+1), rankv(n+1,0) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rankv[a] < rankv[b]) swap(a,b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto &e : connections) dsu.unite(e[0], e[1]);

        // Build component -> online members (initially all online)
        unordered_map<int, set<int>> onlineMembers;
        for (int i = 1; i <= c; ++i) {
            int root = dsu.find(i);
            onlineMembers[root].insert(i);
        }

        vector<char> online(c+1, 1); // 1 = online, 0 = offline
        vector<int> ans;

        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];

            if (type == 1) {
                if (online[x]) {
                    // If x is online, it resolves the check itself
                    ans.push_back(x);
                } else {
                    int root = dsu.find(x);
                    auto &s = onlineMembers[root];
                    if (s.empty()) ans.push_back(-1);
                    else ans.push_back(*s.begin()); // smallest online id in component
                }
            } else if (type == 2) {
                if (online[x]) {
                    online[x] = 0;
                    int root = dsu.find(x);
                    // remove x from online members of its component
                    auto itRoot = onlineMembers.find(root);
                    if (itRoot != onlineMembers.end()) itRoot->second.erase(x);
                }
            }
        }

        return ans;
    }
};
