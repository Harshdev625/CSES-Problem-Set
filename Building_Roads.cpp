#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvvi vector<vector<vector<ll>>>
#define mll map<ll, ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sz size()
#define f first
#define s second
#define nl endl
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define init(a,n) for(ll i=0; i<n; i++) { cin>>a[i]; }
#define print(a) for(const auto&i: (a)){cerr<<i<<" ";}cerr<<nl;

class DisjointSet {
    vll parent, rank, size;
public:
    DisjointSet(ll n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0LL);
        size.resize(n + 1, 1LL);
        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    ll finduparent(ll n) {
        if (n == parent[n]) return n;
        return parent[n] = finduparent(parent[n]);
    }

    void unionbyrank(ll u, ll v) {
        ll upu = finduparent(u);
        ll upv = finduparent(v);
        if (upu == upv) return;
        if (rank[upu] > rank[upv]) {
            parent[upv] = upu;
        } else if (rank[upv] > rank[upu]) {
            parent[upu] = upv;
        } else {
            parent[upv] = upu;
            rank[upu]++;
        }
    }

    void unionbysize(ll u, ll v) {
        ll upu = finduparent(u);
        ll upv = finduparent(v);
        if (upu == upv) return;
        if (size[upu] > size[upv]) {
            parent[upv] = upu;
            size[upu] += size[upv];
        } else {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
    }

    void edge(ll n){
        set<ll>st;
        vll v;
        for(int i=1;i<=n;i++){
            if(parent[i]==i)st.insert(parent[i]);
        }
        for(auto it:st){
            v.pb(it);
        }
        
        cout<<st.size()-1<<nl;
        for(int i=1;i<v.size();i++){
            cout<<v[0]<<" "<<v[i]<<nl;
        }
    }
};

void solve(){
    ll n,m;
    cin>>n>>m;
    vvll graph(n+1);
    ll a,b;
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ds.unionbysize(a,b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    ds.edge(n);
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}