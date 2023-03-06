#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
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
	ll n,sum;
    cin>>n>>sum;
    vector<pair<ll,ll>>a;
    ll t;
    for(int i=0;i<n;i++){
        cin>>t;
        a.push_back({t,i+1});
    }
    sort(a.begin(),a.end());
    int flag=0;
    pair<ll,ll>ans;
    for(int i=0,j=a.size()-1;j>i;){
        if(a[i].first+a[j].first==sum){
            flag=1;
            ans={a[i].second,a[j].second};
            break;
        }
        else if(a[i].first+a[j].first<sum){
            i++;
        }
        else{
            j--;
        }
    }
    if(flag==1){
        cout<<ans.first<<" "<<ans.second;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
	return 0;
}
