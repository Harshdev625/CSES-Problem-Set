#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
    // your code goes here
    string s;
    cin>>s;
    ll a[26]={0};
    for(int i=0;i<s.size();i++){
        a[s[i]-'A']++;
    }
    int count=0;
    int c=-1;
    for(int i=0;i<26;i++){
        if(a[i]%2==1){
            count++;
            c=i;
        }
    }
    if(count>1){
        cout<<"NO SOLUTION";
    }
    else{
        string d,b;
        for(int i=0;i<26;i++){
            if(i==c){
                for(int j=0;j<a[i]/2;j++){
                    d+='A'+i;
                }
            }
            else{
                for(int j=0;j<a[i]/2;j++){
                    d+='A'+i;
                }
            }
        }
        b=d;
        reverse(b.begin(),b.end());
        if(c!=-1)
        d+='A'+c;
        d+=b;
        cout<<d;
    }
    return 0;
}
