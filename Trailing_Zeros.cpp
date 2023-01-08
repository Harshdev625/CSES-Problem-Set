#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    int t;
    cin>>t;
    ll a[12];
    a[0]=5;
    for(int i=1;i<=11;i++){
        a[i]=a[i-1]*5;
    }
    ll ans=0;
    int j=0;
    while(t/a[j]!=0){
        ans+=t/a[j];
        j++;
    }
    cout<<ans;
    return 0;
}
