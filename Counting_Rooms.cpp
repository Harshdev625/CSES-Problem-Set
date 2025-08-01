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


void dfs(ll i,ll j,ll &n,ll &m,vvll &visited,vector<string>&v){
    if(i<0 || j<0 || j>=m || i>=n || visited[i][j] || v[i][j]=='#')return;
    visited[i][j]=1;
    dfs(i-1,j,n,m,visited,v);
    dfs(i+1,j,n,m,visited,v);
    dfs(i,j-1,n,m,visited,v);
    dfs(i,j+1,n,m,visited,v);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    vector<string>v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    vvll visited(n,vll(m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!visited[i][j] && v[i][j]=='.'){
                ans++;
                dfs(i,j,n,m,visited,v);
            }
        }
    }
    cout<<ans<<nl;
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