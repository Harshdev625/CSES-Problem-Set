#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define pb push_back
#define f first
#define s second
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n;
    cin>>n;
    vector<int>v(n+1);
    vector<int>found(n+1,0);
    int round=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        found[v[i]]=i;
    }
    for(int i=2;i<=n;i++){
        if(found[i]<found[i-1])round++;
    }
	cout<< round+1;
}
