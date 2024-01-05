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

int recursion(int i,int &n,int &x,vi&v){
    if(i==n)return 1;
    int ans=0;
    if(v[i]){
        if(i==0 || abs(v[i]-v[i-1])<=1)ans=(ans%MOD + (recursion(i+1,n,x,v)%MOD))%MOD;
    }
    else{
        for(int j=1;j<=x;j++){
            if(i==0 || abs(v[i-1]-j)<=1){
                v[i]=j;
                ans=(ans%MOD + (recursion(i+1,n,x,v)%MOD))%MOD;
                v[i]=0;
            }
        }
    }
    return ans;
}

int memoization(int i,int &n,int &x,vi&v,vi&dp){
    if(i==n)return 1;
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    if(v[i]){
        if(i==0 || abs(v[i]-v[i-1])<=1)ans=(ans%MOD + (memoization(i+1,n,x,v,dp)%MOD))%MOD;
        else return 0;
    }
    else{
        for(int j=1;j<=x;j++){
            if(i==0 || abs(v[i-1]-j)<=1){
                v[i]=j;
                ans=(ans%MOD + (memoization(i+1,n,x,v,dp)%MOD))%MOD;
                v[i]=0;
            }
        }
    }
    return dp[i]=ans;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n,x;
    cin>>n>>x;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vi dp(n+1,-1);
    int ans=memoization(0,n,x,v,dp);
    cout<<ans;
	return 0;
}
