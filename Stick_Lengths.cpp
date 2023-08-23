#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    int median = v[n / 2];  
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(v[i] - median);
    }
    cout << cost;
    return 0;
}
