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

ll helper(ll i,ll j,ll &n,ll&m,string&s,string&t,vvll &dp){
    if(i==n)return m-j;
    if(j==m)return n-i;
    ll ans=INT_MAX;
    if(dp[i][j]!=INT_MAX)return dp[i][j];
    if(s[i]==t[j]){
        ans=helper(i+1,j+1,n,m,s,t,dp);
    }
    else{
        ans= min(ans,1+helper(i+1,j,n,m,s,t,dp));
        ans= min(ans,1+helper(i,j+1,n,m,s,t,dp));
        ans= min(ans,1+helper(i+1,j+1,n,m,s,t,dp));
    }
    return dp[i][j]=ans;
}

void solve(){
    string s,t;
    cin>>s>>t;
    ll n=s.size(),m=t.size();
    vvll dp(n+1,vll(m+1,INT_MAX));
    cout<<helper(0,0,n,m,s,t,dp)<<nl;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}