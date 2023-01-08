#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long int
#define INF 1e9
signed main() {
    // your code goes here
    int t;
    cin>>t;
    int n,m,l;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        if(m>n && m%2==0){
            l=(m-1)*(m-1)+n;
            // cout<<l;
        }
        else if(m>n &&  m%2==1){
            l=(m*m)+1-n;
            // cout<<l;
        }
        else if(n>m && n%2==0){
            l=(n*n)+1-m;
            // cout<<l;
        }
        else if(n>m && n%2==1){
            l=(n-1)*(n-1)+m;
            // cout<<l;
        }
        else{
            l=(m*n)-m+1;
            // cout<<m*n-m+1;
        }
        cout<<l<<nl;
    }
    return 0;
}
