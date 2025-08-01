#include <bits/stdc++.h>
using namespace std;

#define pll pair<int, int>
#define vll vector<int>
#define vvll vector<vector<int>>

vll dx = {1, 0, -1, 0};
vll dy = {0, 1, 0, -1};
string directions = "DRUL";

bool check(int i, int j, int n, int m, vvll &visited, vector<string> &v) {
    return !(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || v[i][j] == '#');
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vvll visited(n, vll(m, 0));
    for (int i = 0; i < n; i++) cin >> v[i];

    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'A') {
                x1 = i;
                y1 = j;
            } else if (v[i][j] == 'B') {
                x2 = i;
                y2 = j;
            }
        }
    }

    if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<pll>> parent(n, vector<pll>(m, {-1, -1}));
    queue<pll> q;
    q.push({x1, y1});
    visited[x1][y1] = 1;

    while (!q.empty()) {
        pll p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (check(nx, ny, n, m, visited, v)) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                parent[nx][ny] = {p.first, p.second};
                if (nx == x2 && ny == y2) break;
            }
        }
    }

    if (!visited[x2][y2]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<char> path;
        int cx = x2, cy = y2;
        while (cx != x1 || cy != y1) {
            pll p = parent[cx][cy];
            for (int i = 0; i < 4; i++) {
                if (p.first == cx - dx[i] && p.second == cy - dy[i]) {
                    path.push_back(directions[i]);
                    break;
                }
            }
            cx = p.first;
            cy = p.second;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (char c : path) cout << c;
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
