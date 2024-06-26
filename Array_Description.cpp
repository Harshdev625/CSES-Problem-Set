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

ll helper(ll i,ll last,ll&n,ll&m,vll &v,vvll &dp){
    if(i==n)return 1;
    if(i>0 && v[i]!=0 && abs(v[i]-last)>1)return 0;
    if(dp[i][last]!=-1)return dp[i][last];
    ll ans=0;
    if(v[i]==0){
        for(ll j=1;j<=m;j++){
            v[i]=j;
            if(i>0 && abs(v[i]-last)<=1)ans+= helper(i+1,v[i],n,m,v,dp);
            else if(i==0)ans+= helper(i+1,v[i],n,m,v,dp);
            v[i]=0;
            ans%=MOD;
        }
    }
    else{
        ans+=helper(i+1,v[i],n,m,v,dp);
        ans%=MOD;
    }
    return dp[i][last]=ans%MOD;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vll v(n);
    init(v,n);
    vvll dp(n+1,vll(m+1,0));
    
    if (v[n-1] == 0) {
        for (ll j = 1; j <= m; ++j) {
            dp[n-1][j] = 1;
        }
    } else {
        dp[n-1][v[n-1]] = 1;
    }

    for (ll i = n-2; i >= 0; --i) {
        for (ll j = 1; j <= m; ++j) {
            if (v[i] == 0 || v[i] == j) {
                dp[i][j] = dp[i+1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i+1][j+1]) % MOD;
            }
        }
    }

    ll result = 0;
    if (v[0] == 0) {
        for (ll j = 1; j <= m; ++j) {
            result = (result + dp[0][j]) % MOD;
        }
    } else {
        result = dp[0][v[0]];
    }

    cout << result << endl;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}