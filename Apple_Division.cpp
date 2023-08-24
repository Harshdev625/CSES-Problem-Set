#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
ll mini =LLONG_MAX;
void calculation(vector<ll>&v,int start,int end, ll a,ll b){
    if(start==end+1){
        mini=min(abs(a-b),mini);
        return ;
    }
    calculation(v,start+1,end,a+v[start],b);
    calculation(v,start+1,end,a,b+v[start]);
}
int main() {
    // your code goes here
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    calculation(v,0,n-1,0,0);
    cout<<mini;
    return 0;
}
