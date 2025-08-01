#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvvi vector<vector<vector<int>>>
#define vll vector<long long>
#define mii map<int, int>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sz size()
#define f first
#define s second
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define init(a,n) for(ll i=0; i<n; i++) { cin>>a[i]; }
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define print(a) for(const auto&i: (a)){cout<<i<<" ";}

set <ll> factors(ll n){
    set<ll>s;
    s.insert(1);
    s.insert(n);
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    return s;
}

vector<ll> primes(){
    vector<ll>primes;
    vector<bool>is_prime(100001, true);
    is_prime[0]=is_prime[1]=false;
    for(ll i=2; i*i<=100000; i++){
        if(is_prime[i]){
            for(ll j=i*i; j<=100000; j+=i){
                is_prime[j]=false;
            }
        }
    }
    for(ll i=2; i<=100000; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

ll helper(ll n,ll m,vvll&dp){
    if(n==m)return 0;
    if(dp[n][m]!=INF)return dp[n][m];
    ll ans=INF;
    for(ll i=1;i<n;i++){
        ans=min(ans,1+helper(i,m,dp)+helper(n-i,m,dp));
    }
    for(ll i=1;i<m;i++){
        ans=min(ans,1+helper(n,i,dp)+helper(n,m-i,dp));
    }
    return dp[n][m]=ans;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vvll dp(n+1,vll(m+1,INF));
    for(ll i=0;i<=min(n,m);i++)dp[i][i]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(i==j)continue;
            ll ans=INF;
            for(ll k=1;k<i;k++){
                ans=min(1+dp[k][j]+dp[i-k][j],ans);
            }
            for(ll k=1;k<j;k++){
                ans=min(1+dp[i][k]+dp[i][j-k],ans);
            }
            dp[i][j]=ans;
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cerr<<dp[i][j]<<" ";
    //     }
    //     cerr<<nl;
    // }
    cout<<dp[n][m]<<nl;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}