#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    int t;
    cin>>t;
    int a;
    set<int>s;
    while(t--){
        cin>>a;
        s.insert(a);
    }
    cout<<s.size();
    return 0;
}

