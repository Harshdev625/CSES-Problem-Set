#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
unordered_map<string,int>m;
vector<string>permutation;
void next_permutation(string &s, int left ,int right){
    if (left ==right){
        if(!m[s]){
            permutation.push_back(s);
            m[s]=1;
        }
        return ;
    } 
    for(int i=left;i<=right;i++){
        swap(s[left],s[i]);
        next_permutation(s,left+1,right);
        swap(s[left],s[i]);
    }
}
int main() {
    // your code goes here
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    next_permutation(s,0,s.size()-1);
    sort(permutation.begin(),permutation.end());
    cout<<permutation.size()<<nl;
    for(auto &i:permutation){
        cout<<i<<nl;
    }
    return 0;
}
