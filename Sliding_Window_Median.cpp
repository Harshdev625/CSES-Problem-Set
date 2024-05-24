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
#define print(a) for(const auto&i: (a)){cerr<<i<<" ";}

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
    ll n,k;
    cin>>n>>k;
    vll a(n);
    init(a,n);
    multiset<ll>b,c;
    for(int i=0; i<k; i++){
        if(b.empty() || a[i]<=*b.rbegin()){
            b.insert(a[i]);
        }
        else c.insert(a[i]);
        while((int)b.sz -(int)c.sz>1){
            auto it = prev(b.end());
            c.insert(*it);
            b.erase(it);
        }
        while((int)b.sz -(int)c.sz<0){
            auto it = c.begin();
            b.insert(*it);
            c.erase(it);
        }
        while(!c.empty() && *b.rbegin()>*c.begin()){
            auto it = prev(b.end());
            c.insert(*it);
            b.erase(it);
            it = c.begin();
            b.insert(*it);
            c.erase(it);
        }
    }
    for(int i=k;i<=n;i++){
        // print(b);cerr<<nl;
        // print(c);cerr<<nl;
        cout<<*b.rbegin()<<" ";
        if(i==n)break;
        if(b.find(a[i-k])!=b.end()){
            b.erase(b.find(a[i-k]));
        }
        else c.erase(c.find(a[i-k]));
        if(b.empty() || a[i]<=*b.rbegin()){
            b.insert(a[i]);
        }
        else c.insert(a[i]);
        while((int)b.sz -(int)c.sz>1){
            auto it = prev(b.end());
            c.insert(*it);
            b.erase(it);
        }
        while((int)b.sz -(int)c.sz<0){
            auto it = c.begin();
            b.insert(*it);
            c.erase(it);
        }
        while(!c.empty() && *b.rbegin()>*c.begin()){
            auto it = prev(b.end());
            c.insert(*it);
            b.erase(it);
            it = c.begin();
            b.insert(*it);
            c.erase(it);
        }
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