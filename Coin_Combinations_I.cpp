#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int> 
#define vvi vector<vector<int>>
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
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n,total;
    cin >> n >> total;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vvi dp(n,vi(total+1,0));
    for(int i=0;i<=total;i++){
        if(i % v[0] == 0)dp[0][i]= 1;
    }
    for(int i=0;i<=total;i++){
        if(i % v[0] == 0)dp[0][i]= 1;
        else dp[0][i]=0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=total;j++){
            dp[i][j]= ((j-v[i]>=0) ? dp[i][j-v[i]] : 0)+dp[i-1][j];
        }
    }
    cout << dp[n - 1][total] << nl;
    return 0;
}
