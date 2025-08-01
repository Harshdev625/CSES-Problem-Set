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
#define print(a) for(const auto&i: (a)){cout<<i<<" ";}cout<<nl;

void solve(){
    ll n,m;
    cin>>n>>m;
    vvll graph(n+1);
    ll a,b;
    vll parent(n+1,-1);
    vll visited(n+1,INF);
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        graph[b].pb(a);
        graph[a].pb(b);
    }
    queue<pll>q;
    visited[1]=1;
    q.push({1,1});
    while(!q.empty()){
        pll p=q.front();
        q.pop();
        for(auto it:graph[p.s]){
            if(visited[it]> p.f +visited[p.s]){
                parent[it]=p.s;
                visited[it]=1+p.f;
                q.push({visited[it],it});
            }
        }
    }
    if(visited[n]==INF){
        cout<<"IMPOSSIBLE"<<nl;
    }
    else{
        cout<<visited[n]<<nl;
        vll v;
        while(n!=-1){
            v.pb(n);
            n=parent[n];
        }
        reverse(all(v));
        print(v);
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