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
	int t;
	cin>>t;
    int a,b;
    vector<pair<int,int>>v;
	while(t--){
		cin>>a>>b;
        v.push_back({a,b});
	}
    sort(v.begin(),v.end());
    pair<int,int>p=v[0];
    int count=1;
    for(int i=1;i<v.size();i++){
        if(v[i].first>=p.second){
            count++;
            p=v[i];
        }
        else if ( v[i].second< p.second)p=v[i];
    }
	cout<<count;
}
