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

int recursion(int i,int n,int x,vi&book,vi&page){
    if(i==n)return 0;
    int nottake=recursion(i+1,n,x,book,page);
    int take=INT_MIN;
    if(book[i]<=x)take=page[i]+recursion(i+1,n,x-book[i],book,page);
    return max(take,nottake);
}

int memoization(int i,int n,int x,vi&book,vi&page,vvi&dp){
    if(i==n)return 0;
    if(dp[i][x]!=-1)return dp[i][x];
    int nottake=memoization(i+1,n,x,book,page,dp);
    int take=INT_MIN;
    if(book[i]<=x)take=page[i]+memoization(i+1,n,x-book[i],book,page,dp);
    return dp[i][x]=max(take,nottake);
}

int dynamic_programming(int n,int x,vi&page,vi&book){
    vvi dp(n+1,vi(x+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=x;j>=0;j--){
            int nottake=dp[i+1][j];
            int take=0;
            if(book[i]<=j)take=page[i]+dp[i+1][j-book[i]];
            dp[i][j]=max(take,nottake);
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=x;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    return dp[0][x];
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n,x;
    cin>>n>>x;
    vi page(n);
    vi book(n);
    for(int i=0;i<n;i++)cin>>book[i];
    for(int i=0;i<n;i++)cin>>page[i];
    // vvi dp(n+1,vi(x+1,-1));    
    int ans=dynamic_programming(n,x,page,book);
    cout<<ans;
	return 0;
}
