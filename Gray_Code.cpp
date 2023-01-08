#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
void graycode(int i,int t){
    string s,s1;
    while(i!=0){
        if(i%2==0){
            s.push_back('0');
        }
        else{
            s.push_back('1');
        }
        i/=2;
    }
    reverse(s.begin(),s.end());
    s1=s;
    for(int i=1;i<s.size();i++){
        if((s[i]=='0' && s[i-1]=='1') || (s[i]=='1' && s[i-1]=='0')){
            s1[i]='1';
        }
        else{
            s1[i]='0';
        }
    }
    if(s.size()<t){
        int l =t-s.size();
        while(l--){
            cout<<0;
        }
    }
    cout<<s1<<endl;;
}
int main() {
    // your code goes here
    int t;
    cin>>t;
    for(int i=0;i<pow(2,t);i++){
        graycode(i,t);
    }
    return 0;
}
