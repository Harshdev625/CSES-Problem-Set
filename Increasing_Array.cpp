#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define INF 1e9
signed main() {
    // your code goes here
    int t;
    cin>>t;
    int arr[t];
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=1;i<t;i++){
        if(arr[i]<arr[i-1]){
            ans+=abs(arr[i]-arr[i-1]);
            arr[i]=arr[i-1];
        }
    }
    cout<<ans;
    return 0;
}
