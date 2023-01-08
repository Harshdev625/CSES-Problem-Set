#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
void towerofhanoi(int t,int a,int b,int c){
    if(t>0){
        towerofhanoi(t-1, a, c, b);
        cout<<a<<" "<<c<<endl;
        towerofhanoi(t-1, b, a, c);
    }
}
int main() {
    // your code goes here
    int t;
    cin>>t;
    cout<<pow(2,t)-1<<endl;
    towerofhanoi(t,1,2,3);
    return 0;
}
