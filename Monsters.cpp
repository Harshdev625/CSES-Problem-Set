#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>

vll dx = {1, 0, -1, 0};
vll dy = {0, 1, 0, -1};
string directions = "DRUL";

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> distFromMonsters(n, vector<int>(m, INT_MAX));
    vector<vector<int>> distFromPlayer(n, vector<int>(m, -1));
    queue<pll> monsters;
    pll start;

    // Initialize queues for player and monsters
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (v[i][j] == 'A') {
                start = {i, j};
            } else if (v[i][j] == 'M') {
                monsters.push({i, j});
                distFromMonsters[i][j] = 0;
            }
        }
    }
    if(start.first==0 && start.second==0){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    else if(start.first==0 && start.second==m-1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    else if(start.first==n-1 && start.second==0){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    else if(start.first==n-1 && start.second==m-1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    // BFS for monsters' movement
    while (!monsters.empty()) {
        pll p = monsters.front();
        monsters.pop();
        for (ll i = 0; i < 4; i++) {
            ll nx = p.first + dx[i];
            ll ny = p.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '.' && distFromMonsters[nx][ny] == INT_MAX) {
                distFromMonsters[nx][ny] = distFromMonsters[p.first][p.second] + 1;
                monsters.push({nx, ny});
            }
        }
    }

    // BFS for player's movement
    queue<pll> playerQueue;
    playerQueue.push(start);
    distFromPlayer[start.first][start.second] = 0;

    vector<vector<pll>> parent(n, vector<pll>(m, {-1, -1}));
    bool found = false;
    pll end;

    while (!playerQueue.empty() && !found) {
        pll p = playerQueue.front();
        playerQueue.pop();
        for (ll i = 0; i < 4; i++) {
            ll nx = p.first + dx[i];
            ll ny = p.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '.' && distFromPlayer[nx][ny] == -1) {
                if (distFromPlayer[p.first][p.second] + 1 < distFromMonsters[nx][ny]) {
                    distFromPlayer[nx][ny] = distFromPlayer[p.first][p.second] + 1;
                    parent[nx][ny] = p;
                    playerQueue.push({nx, ny});
                    if (nx == 0 || nx == n-1 || ny == 0 || ny == m-1) {
                        found = true;
                        end = {nx, ny};
                        break;
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        string path;
        pll p = end;
        while (p != start) {
            pll prev = parent[p.first][p.second];
            for (ll i = 0; i < 4; i++) {
                if (prev.first == p.first - dx[i] && prev.second == p.second - dy[i]) {
                    path.push_back(directions[i]);
                    break;
                }
            }
            p = prev;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
