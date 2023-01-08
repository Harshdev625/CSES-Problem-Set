#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll c=((2*a)-b)/3;
        ll d=((2*b)-a)/3;
        if((2*c)+d==a && (2*d)+c==b && c>=0 && d>=0){
            cout<<"YES"<<nl;
        }
        else{
            cout<<"NO"<<nl;
        }
    }
    return 0;
}
