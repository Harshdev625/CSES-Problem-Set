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
int recursion(int i,int j,int n,vector<vector<char>>&grid){
    if(i>=n || j>=n)return 0;
    if(i==n-1 && j==n-1)return grid[i][j]=='.';
    if(grid[i][j]=='*')return 0;
    int down=recursion(i,j+1,n,grid);
    int left=recursion(i+1,j,n,grid);
    return (left%MOD+down%MOD)%MOD;
}
int memoization(int i,int j,int n,vector<vector<char>>&grid,vvi &dp){
    if(i>=n || j>=n)return 0;
    if(i==n-1 && j==n-1)return grid[i][j]=='.';
    if(grid[i][j]=='*')return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int down=memoization(i,j+1,n,grid,dp);
    int left=memoization(i+1,j,n,grid,dp);
    return dp[i][j]=(left%MOD+down%MOD)%MOD;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vvi dp(n,vi(n,-1));
    int ans=memoization(0,0,n,grid,dp);
    cout<<ans;
	return 0;
}
