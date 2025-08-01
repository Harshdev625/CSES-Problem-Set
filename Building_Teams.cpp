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

void dfs(ll node,vll &visited,vvll&graph,bool &np){
    
    for(auto it:graph[node]){
        if(visited[it]==-1){
            visited[it]=!visited[node];
            dfs(it,visited,graph,np);
        }
        else{
            if(visited[it]==visited[node]){
                np=true;
            }
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll a,b;
    vvll graph(n+1);
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vll visited(n+1,-1);
    bool np=false;
    for(ll i=1;i<=n;i++){
        if(visited[i]==-1){
            visited[i]=1;
            dfs(i,visited,graph,np);
        }
    }
    if(!np){
        for(ll i=1;i<=n;i++){
            cout<<visited[i]+1<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
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