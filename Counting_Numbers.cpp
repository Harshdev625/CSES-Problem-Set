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

ll dp [20][2][2][11];

string oneless(string &s) {
    string res=s;
    for(ll i = res.size()-1;i>=0;i--){
        if(res[i]=='0')res[i]='9';
        else {
            res[i]--;
            break;
        }
    }
    ll start = 0;
    while (start < res.size() && res[start] == '0') start++;
    if (start == res.size()) return "0";
    return res.substr(start);
}

ll helper (ll i,bool flag ,bool num,ll last,string &s){
    if(i==s.size())return 1;
    if(dp[i][flag][num][last+1]!=-1)return dp[i][flag][num][last+1];
    ll ans =0;
    ll limit = (flag?s[i]-'0':9);
    for(ll j=0; j<=limit; j++){
        if(j==last && num) continue;
        ans+=helper(i+1,flag&(s[i]-'0'==j),num | (j>0),j,s);
    }
    return dp[i][flag][num][last+1]=ans;
}

void solve(){
    string s1 ,s2;
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    ll right = helper(0,1,0,-1,s2);
    ll left =0;
    if(s1 != "0"){
        string s3 = oneless(s1);
        memset(dp,-1,sizeof(dp));
        left = helper(0,1,0,-1,s3);
    }
    cout<<right-left<<nl;
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