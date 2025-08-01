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

class SegmentTree {
    vector<ll> seg;

public:
    SegmentTree(ll n) {
        seg.resize(4 * n + 1, 0);
    }

    void build(ll index, ll l, ll h, vll &v) {
        if (l == h) {
            seg[index] = v[l];
            return;
        }
        ll mid = l + (h - l) / 2;
        build(2 * index + 1, l, mid, v);
        build(2 * index + 2, mid + 1, h, v);
        seg[index] = max( seg[2 * index + 1] , seg[2 * index + 2]);
    }

    void update(ll index, ll low, ll high, ll pos, ll val) {
        if (low == high) {
            seg[index] = val;
            return;
        }
        ll mid = low + (high - low) / 2;
        if (pos <= mid) {
            update(2 * index + 1, low, mid, pos, val);
        } else {
            update(2 * index + 2, mid + 1, high, pos, val);
        }
        seg[index] = max(seg[2 * index + 1] , seg[2 * index + 2]);
    }

    ll query(ll index, ll low, ll high, ll l, ll r) {
        if (l > high || r < low) return 0;
        if (low >= l && high <= r) return seg[index];
        ll mid = low + (high - low) / 2;
        ll left = query(2 * index + 1, low, mid, l, r);
        ll right = query(2 * index + 2, mid + 1, high, l, r);
        return max(left , right);
    }
};

void solve(){
    ll n,m;
    cin>>n>>m; 
    vll a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SegmentTree seg(n);
    seg.build(0,0,n-1,a);
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(seg.query(0,0,n-1,0,n-1) <b[i]){
            cout<<0<<" ";
        }
        else{
            ll low=0,high=n-1;
            while(low<=high){
                ll mid=low + (high-low)/2;
                if(seg.query(0,0,n-1,0,mid)>=b[i]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            cout<<low+1<<" ";
            a[low]-=b[i];
            seg.update(0,0,n-1,low,a[low]);
        }
    }
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