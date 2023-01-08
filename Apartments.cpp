#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    int n,m,k;
    cin>>n>>m>>k;
    ll a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    ll ans=0;
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0,j=0;i<n && j<m;){
        if(b[j]-k <=a[i] && a[i]<=b[j]+k){
            ans++;
            i++;
            j++;
        }
        else if(a[i]>b[j]+k  ){
            j++;
        }
        else{
            i++;
        }
    }
    cout<<ans;
    return 0;
}
