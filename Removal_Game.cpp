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
 
ll helper(int i,int j,vll&v,vvll&dp){
    if(i>j)return 0;
    if(i==j)return v[i];
    if(j-i==1)return max(v[i],v[j]);
    if(dp[i][j]!=0)return dp[i][j];
    return dp[i][j]=max(v[i]+min(helper(i+2,j,v,dp),helper(i+1,j-1,v,dp)),v[j]+min(helper(i,j-2,v,dp),helper(i+1,j-1,v,dp)));
}
 
void solve(){
    ll n;
    cin>>n;
    vll v(n);
    init(v,n);
    vvll dp(n,vll(n,0));
 
    for(int i=0;i<n;i++)dp[i][i]=v[i];
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(i>j)continue;
            if(j-i==1){
                dp[i][j]=max(v[i],v[j]);
                continue;
            }
            ll a = (i+2<n)?dp[i+2][j]:0;
            ll b = (i+1<n && j-1>=0)?dp[i+1][j-1]:0;
            ll c = (j-2>=0)?dp[i][j-2]:0;
            dp[i][j]=max(v[i]+min(a,b),v[j]+min(c,b));
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cerr<<dp[i][j]<<" ";
    //     }
    //     cerr<<nl;
    // }
    cout<<dp[0][n-1]<<nl;
}
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}