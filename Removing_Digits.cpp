#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vll vector<long long>
#define mii map<int, int>
#define pb push_back
#define f first
#define s second
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

ll recursion(ll n){
    if(n==0)return 0;
    vi v;
    ll t=n;
    while(t){
        v.pb(t%10);
        t/=10;
    }
    ll ans=INF;
    for(ll i=0;i<v.size();i++){
        if(v[i])ans=min(ans,1+recursion(n-v[i]));
    }
    return ans;
}
ll memoization(ll n,vll&dp){
    if(n==0)return dp[n]=0;
    if(dp[n]!=INF)return dp[n];
    vll v;
    ll t=n;
    while(t){
        v.pb(t%10);
        t/=10;
    }
    ll ans=INF;
    for(ll i=0;i<v.size();i++){
        if(v[i])ans=min(ans,1+memoization(n-v[i],dp));
    }
    return dp[n]=ans;
}
ll dynamic_programming(ll n){
    vll dp(n+1,INF);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        vll v;
        ll t=i;
        while(t){
            v.pb(t%10);
            t/=10;
        }
        ll ans=INF;
        for(ll j=0;j<v.size();j++){
            if(v[j] )ans=min(ans,1+dp[i-v[j]]);
        }
        dp[i]=min(dp[i],ans);
    }
    // for(auto&i:dp){
    //     cout<<i<<" ";
    // }
    // cout<<nl;
    return dp[n];
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	ll n;
    cin>>n;
    vll dp(n+1,INF);
    ll ans=dynamic_programming(n);
    cout<<ans;
	return 0;
}
