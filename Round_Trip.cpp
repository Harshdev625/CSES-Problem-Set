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
#define debug(a) for(const auto&i: (a)){cerr<<i<<" ";}cerr<<nl;
 
void dfs(ll node,vvll&graph,vll&visited,vll&parent,vll&ans){
    visited[node]=1;
    for(auto it:graph[node]){
        if(!visited[it]){
            parent[it]=node;
            dfs(it,graph,visited,parent,ans);
            if(!ans.empty())return;
        }
        else{
            if(it==parent[node])continue;
            else{
                vll v;
                v.push_back(it);
                ll current=node;
                while(current!=it){
                    v.pb(current);
                    current=parent[current];
                }
                v.pb(it);
                if(v.size()>=4){
                    ans=v;
                    return;
                }
            }
        }
    }
}
 
void solve(){
    ll n,m;
    cin>>n>>m;
    vvll graph(n+1);
    ll a,b;
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    // for(auto it:graph){
    //     debug(it);
    // }
    vll parent(n+1,-1);
    vll visited(n+1,0);
    vll ans;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,graph,visited,parent,ans);
            if(ans.size())break;
        }
    }
    if(ans.size()){
        cout<<ans.size()<<nl;
        print(ans);
    }
    else cout<<"IMPOSSIBLE"<<nl;
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