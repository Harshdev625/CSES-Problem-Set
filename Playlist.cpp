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
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<int>m;
    int ans=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(m.find(v[i])==m.end()){
            m.insert(v[i]);
        }
        else{
            while(m.find(v[i])!=m.end()){
                m.erase(v[l]);
                l++;
            }
            m.insert(v[i]);
        }
        ans= max(ans,i-l+1);
    }
    cout<<ans<<nl;
	return 0;
}

