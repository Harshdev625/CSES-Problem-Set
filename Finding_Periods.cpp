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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define sz(v) ((int)(v).size())
#define f first
#define s second
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define init(a, n) for (ll i = 0; i < n; i++) { cin >> a[i]; }
#define F0R(i, a) for (ll i = 0; i < (a); i++)
#define print(a) for (const auto &i : (a)) { cerr << i << " "; } cerr << nl

class HashedString {
private:
    static const ll M1 = 1e9 + 9;
    static const ll B1 = 9973;
    static const ll M2 = 1e9 + 7;
    static const ll B2 = 10007;

    static inline vll pow1 = {1};
    static inline vll pow2 = {1};
    vll p_hash1, p_hash2;

public:
    HashedString(const string &s) : p_hash1(sz(s) + 1), p_hash2(sz(s) + 1) {
        while (sz(pow1) <= sz(s)) {
            pow1.pb((pow1.back() * B1) % M1);
        }
        while (sz(pow2) <= sz(s)) {
            pow2.pb((pow2.back() * B2) % M2);
        }

        p_hash1[0] = 0;
        p_hash2[0] = 0;
        F0R(i, sz(s)) {
            p_hash1[i + 1] = ((p_hash1[i] * B1) % M1 + s[i]) % M1;
            p_hash2[i + 1] = ((p_hash2[i] * B2) % M2 + s[i]) % M2;
        }
    }

    pll get_hash(int start, int end) {
        if (start > end) return {0, 0};
        ll raw_val1 = (p_hash1[end + 1] - (p_hash1[start] * pow1[end - start + 1]) % M1 + M1) % M1;
        ll raw_val2 = (p_hash2[end + 1] - (p_hash2[start] * pow2[end - start + 1]) % M2 + M2) % M2;
        return {raw_val1, raw_val2};
    }

    static pll concatenate_hashes(const vector<pair<pll, ll>> &hashes) {
        ll combined_hash1 = 0, combined_hash2 = 0, cumulative_length = 0;
        for (const auto &[hash, length] : hashes) {
            auto [hash1, hash2] = hash;
            combined_hash1 = (combined_hash1 * pow1[length] % M1 + hash1) % M1;
            combined_hash2 = (combined_hash2 * pow2[length] % M2 + hash2) % M2;
            cumulative_length += length;

            while (sz(pow1) <= cumulative_length) {
                pow1.pb((pow1.back() * B1) % M1);
            }
            while (sz(pow2) <= cumulative_length) {
                pow2.pb((pow2.back() * B2) % M2);
            }
        }
        return {combined_hash1, combined_hash2};
    }
};

int main() {
    string s;
    cin>>s;
    HashedString hs(s);
    for(ll i=1;i<=s.size();i++){
        bool ans=true;
        pll p =hs.get_hash(0,i-1);
        for(ll j=0;j<s.size();j+=i){
            ll end=min(j+i-1,(ll)s.size()-1);
            pll q=hs.get_hash(j,end);
            // cerr<<p.f<<" "<<p.s<<" "<<q.f<< " "<<q.s<<nl;
            if(end-j+1<i){
                p=hs.get_hash(0,end-j);
                if(p!=q){
                    ans=false;
                    break;
                }
            }
            else if(p!=q){
                ans=false;
                break;
            }
        }
        if(ans )cout<<i<<" ";
    }
}
