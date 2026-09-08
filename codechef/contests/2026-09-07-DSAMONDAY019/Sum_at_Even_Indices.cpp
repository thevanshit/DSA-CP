#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int N;
    ll K;
    cin >> N >> K;

    ll answer = 0;
    for (int i = 0; i < N; ++i) {
        ll value;
        cin >> value;
        if (i % 2 == 0 && value > 2 * K) {
            answer += value;
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}