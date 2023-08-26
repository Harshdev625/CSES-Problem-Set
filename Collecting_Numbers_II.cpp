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
	int n,q;
    cin>>n>>q;
    vector<int>v(n+1,0);
    unordered_map<int,int>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        m[v[i]]=i;
    }
    int round=1;
    for(int i=1;i<=n;i++){
        if(m[i]<m[i-1])round++;
    }
    // cout<<round<<nl;
    int a,b;
    while(q--){
        cin>>a>>b;
        set<pair<int,int>>set_pair;

        if(v[a]-1>0)set_pair.insert({v[a]-1,v[a]});
        if(v[a]+1<=n)set_pair.insert({v[a],v[a]+1});
        if(v[b]-1>0)set_pair.insert({v[b]-1,v[b]});
        if(v[b]+1<=n)set_pair.insert({v[b],v[b]+1});

        for(auto &i:set_pair){
            if(m[i.f]>m[i.s])round--;
            // cout<<i.f<<' '<<i.s<<' '<<m[i.f]<<' '<<m[i.s]<<nl;
        }

        swap(m[v[a]],m[v[b]]);
        swap(v[a], v[b]);

        for(auto &i:set_pair){
            if(m[i.f]>m[i.s])round++;
            // cout<<i.f<<' '<<i.s<<' '<<m[i.f]<<' '<<m[i.s]<<nl;
        }
        cout<<round<<nl;
    }
}
