#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long int
#define INF 1e9
signed main() {
	// your code goes here
	int t;
	cin>>t;
    cout<<t<<" ";
	while(t!=1){
		if(t%2==0){
            t/=2;
        }
        else if(t!=1 && t%2==1){
            t=t*3+1;
        }
        cout<<t<<" ";
	}
	return 0;
}
