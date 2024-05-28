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

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<string>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='*'){
                dp[i+1][j+1]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]<<nl;
    }
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}