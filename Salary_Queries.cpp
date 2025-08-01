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
#define debug(a) for(const auto&i: (a)){cerr<<i<<" ";}cerr<<nl;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

void solve(){
    ll n, q;
    cin >> n >> q;
    vll v(n);
    pbds m;
    init(v, n);
    for(auto&i : v){
        m.insert(i);
    }
    char c;
    ll l, r;
    while(q--){
        cin >> c >> l >> r;
        if(c == '?'){
            cout << m.order_of_key(r + 1) - m.order_of_key(l) << nl;
        }
        else{
            // cerr << v[l-1] << nl;
            auto it = m.find_by_order(m.order_of_key(v[l-1]));
            if (it != m.end() && *it == v[l-1]) {
                m.erase(it);
            }
            v[l-1] = r;
            m.insert(r);
        }
        // debug(m);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
