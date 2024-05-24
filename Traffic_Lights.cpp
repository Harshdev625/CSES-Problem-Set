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
    ll n,k;
    cin>>n>>k;
    vll v(k);
    init(v,k);
    multiset<ll>s,t;
    s.insert(0);
    s.insert(n);
    t.insert(n);
    for(int i=0;i<k;i++){
        s.insert(v[i]);
        auto it = s.find(v[i]);
        auto it1 = prev(it);
        auto it2 = next(it);
        auto it3 =t.find(*it2 -*it1);
        t.erase(it3);
        t.insert(v[i]-*it1);
        t.insert(*it2-v[i]);
        cout<<*t.rbegin()<<" ";
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