#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    ll t;
    cin>>t;
    ll a[t];
    cin>>a[0];
    ll current_sum=a[0];
    ll max_sum=a[0];
    for(int i=1;i<t;i++){
        cin>>a[i];
        current_sum=max(a[i],a[i]+current_sum);
        max_sum=max(max_sum,current_sum);
    }
    cout<<max_sum;
}
