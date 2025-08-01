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
#define min_pq priority_queue<pll, vector<pll>, greater<pll>>
#define init(a,n) for(ll i=0; i<n; i++) { cin>>a[i]; }
#define print(a) for(const auto&i: (a)){cerr<<i<<" ";}cerr<<nl;

void solve(){
    ll n,m;
    cin>>n>>m;
    ll a,b,c;
    vector<vector<pll>> graph(n+1);
    min_pq pq;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        graph[a].pb({b,c});
    }
    vll distance(n+1,INT_MAX);
    // vll parent(n+1,-1);
    distance[1]=0;
    // for(auto [f,s]:graph[1]){
    //     // parent[f]=1;
    //     distance[f]=s;
    //     pq.push({s,f});
    // }
    pq.push({0,1});
    while(!pq.empty()){
        pll p=pq.top();
        pq.pop();
        if(p.f>distance[p.s])continue;
        for(auto [f,s]:graph[p.s]){
            if(distance[f]==INT_MAX || distance[f]>distance[p.s]+s){
                distance[f]=distance[p.s]+s;
                pq.push({distance[f],f});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }
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