#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    int t;
    cin>>t;
    if(t==2 || t==3){
        cout<<"NO SOLUTION";
    }
    else{
        for(int i=2;i<=t;i+=2){
            cout<<i<<" ";
        }
        for(int i=1;i<=t;i+=2){
            cout<<i<<" ";
        }
    }
    return 0;
}
