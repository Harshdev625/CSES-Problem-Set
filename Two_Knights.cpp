#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long int
#define INF 1e9
signed main() {
    // your code goes here
    int t;
    cin>>t;
    int m=0;
    for (int i=1;i<=t; i++){
        if(t==1){
            cout<<0<<nl;
        }
        else{
            int c=(pow(i,2)*(pow(i,2)-1))/2;
            int d=(m)*(m-2);
            cout<< c-d <<nl;
            m+=2;
        }
    }
    return 0;
}
