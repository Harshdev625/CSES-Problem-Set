#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define pb push_back
#define f first
#define s second
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9
int main() {
    // your code goes here
    ll n,k;
    cin>>n>>k;
    vector<ll>v;
    ll t;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    multiset<ll>m;
    for(int i=0;i<k;i++){
        m.insert(v[i]);
    }
    for(int i=k;i<=n;i++){
        auto mid = next(m.begin(), k/2);
        cout << (*mid + *prev(mid, 1-k%2)) / 2.0 << " ";
        m.erase(m.find(v[i-k]));
        m.insert(v[i]);
    }
}
