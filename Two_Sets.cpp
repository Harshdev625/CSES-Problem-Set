#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    ll t;
    cin>>t;
    if((t*(t+1))/2 %2==0){
        vector<ll>a;
        vector<ll>b;
        ll c=t;
        int i=0;
        while(c>=1){
        if(i%2==0 ){
            a.push_back(c);
            c--;
            b.push_back(c);
            c--;
            i++;
        }
        else{
            b.push_back(c);
            c--;
            a.push_back(c);
            c--;
            i++;
        }
        }
        if(t%2==1){
        a.pop_back();
        }
        cout<<"YES"<<nl;
        cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<b.size()<<endl;
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
    }
    else{
        cout<<"NO";
    }
    return 0;
}
