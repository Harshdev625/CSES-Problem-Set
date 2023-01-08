#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    int t;
    cin>>t;
    ll a,ans=0;
    unordered_map<int,int>m;
    while(t--){
        cin>>a;
        if(m[a]==0){
            ans++;
            m[a]++;
        }
        else{
            m[a]++;
        }
    }
    cout<<ans;
    return 0;
}

