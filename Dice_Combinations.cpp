#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1000000007
int main() {
    // your code goes here
    int n;
    cin>>n;
    vector<int>v(n+1,0);
    v[0]=1;
    v[1]=1;
    v[2]=2;
    v[3]=4;
    v[4]=8;
    v[5]=16;
    for(int i=6;i<=n;i++){
        for(int j=1;j<=6;j++){
            v[i]+=v[i-j];
            v[i]%=INF;
        }
    }
    cout<<v[n];
    return 0;
}
