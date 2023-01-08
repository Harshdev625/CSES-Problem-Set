#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int
#define INF 1e9
int main() {
	// your code goes here
	string s;
    cin>>s;
    int arr[26]={0};
    int count=1;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]){
            count++;
        }
        else{
            if(arr[s[i-1]-'A']<count){
                arr[s[i-1]-'A']=count;
            }
            count=1;
        }
        if(i==s.size()-1){
            if(arr[s[i-1]-'A']<count){
                arr[s[i-1]-'A']=count;
            }
            count=1;
        }
    }
    if(s.size()==1){
        cout<<1;
    }
    else{
        cout<<*max_element (arr, arr+26);
    }
	return 0;
}
