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
    unordered_set<int>m;
    int count=0;
    vector<int>list;
    for(int i=0;i<n;i++){
        if(m.find(v[i])==m.end()){
            count++;
            m.insert(v[i]);
        }
        else{
            // cout<<i<<" "<<count<<nl;
            list.push_back(count);
            count=1;
            m.clear(); 
            m.insert(v[i]);
        }
    }

    list.push_back(count);
    int ans= *max_element(list.begin(),list.end());
    ans=max(ans,list[0]+list[list.size()-1]);
    if (ans > n) {
        cout << n;
    } else {
        cout << ans;
    }
    
	return 0;
}

