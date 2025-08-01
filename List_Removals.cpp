#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree {
    vector<ll> seg;
    ll n;

public:
    SegmentTree(ll n) {
        this->n = n;
        seg.resize(4 * n + 1, 0);
    }

    void build(const vector<ll> &v) {
        build(0, 0, n - 1, v);
    }

    void update(ll pos, ll val) {
        update(0, 0, n - 1, pos, val);
    }

    ll query(ll l, ll r) {
        return query(0, 0, n - 1, l, r);
    }

private:
    void build(ll index, ll l, ll h, const vector<ll> &v) {
        if (l == h) {
            seg[index] = v[l];
            return;
        }
        ll mid = l + (h - l) / 2;
        build(2 * index + 1, l, mid, v);
        build(2 * index + 2, mid + 1, h, v);
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
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
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }

    ll query(ll index, ll low, ll high, ll l, ll r) {
        if (l > high || r < low) return 0;
        if (low >= l && high <= r) return seg[index];
        ll mid = low + (high - low) / 2;
        ll left = query(2 * index + 1, low, mid, l, r);
        ll right = query(2 * index + 2, mid + 1, high, l, r);
        return left + right;
    }
};

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n, 1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];

    SegmentTree seg(n);
    seg.build(c);

    for(ll i = 0; i < n; i++){
        ll total = b[i];
        ll index=-1;
        ll low=0,high=n-1;
        while(low<=high){
            ll mid= low + (high-low)/2;
            ll val=seg.query(0,mid);
            if(val>=total){
                index=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout << a[index] << " ";
        seg.update(index, 0);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
