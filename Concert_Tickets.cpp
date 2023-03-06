#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    multiset<int> prices;
    int price;
    for (int i = 0; i < n; i++) {
        cin >> price;
        prices.insert(price);
    }
    int max_price;
    for (int i = 0; i < m; i++) {
        cin >> max_price;
        auto it = prices.lower_bound(max_price);
        if (it == prices.end() || *it > max_price) {
            if (it == prices.begin()) {
                cout << "-1\n";
            } else {
                it--;
                cout << *it << "\n";
                prices.erase(it);
            }
        } else {
            cout << *it << "\n";
            prices.erase(it);
        }
    }
    return 0;
}
