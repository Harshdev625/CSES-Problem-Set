#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    int n,x;
    cin>>n>>x;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    sort(a,a+n);
    for(int i=0,j=n-1;j>i;){
        if(a[i]+a[j]<=x){
            ans++;
            i++;
            j--;        
        }
        else{
            ans++;
            j--;
        }
        if(i==j){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
