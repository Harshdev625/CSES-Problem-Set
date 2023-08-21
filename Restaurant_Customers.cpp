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
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, a, b;
    cin >> t;
    vector<int>v1;
    vector<int>v2;
    while (t--){
        cin>>a>>b;
        v1.push_back(a);
        v2.push_back(b);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int maxi=1;
    int count=0;
    for(int i=0,j=0;i<v1.size();i++){
        while(v1[i]>v2[j]){
            count--;
            j++;
        }
        count++;
        maxi=max(maxi,count);
    }
    cout<<maxi;
}