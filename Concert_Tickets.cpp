#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int search(int n,int a[],int t){
    int s=0;
    int e=t-1;
    
}
int main() {
    // your code goes here
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    for(int i=0;i<m;i++){
        cout<<search(b[i],a,n)<<endl;
    }
    return 0;
}
