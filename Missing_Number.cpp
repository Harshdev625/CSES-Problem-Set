#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long int
#define INF 1e9
signed main() {
	// your code goes here
	int n;
	cin>>n;
    int arr[200001]={0};
    int t;
	for(int i=0;i<n-1;i++){
		cin>>t;
        arr[t]=1;
	}
    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            cout<<i;
            break;
        }
    }
	return 0;
}
