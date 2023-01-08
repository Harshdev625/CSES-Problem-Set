#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
#define mod 1000000007
int main() {
    // your code goes here
    int t;
    cin>>t;
    ll ans=2;
    for(int i=0;i<t-1;i++){
        ans=((ans%mod)*(2))%mod;
    }
    cout<<ans;
    return 0;
}
