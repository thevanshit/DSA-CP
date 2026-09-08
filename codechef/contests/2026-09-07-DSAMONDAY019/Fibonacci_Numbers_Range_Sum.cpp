#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    const int MAX_INDEX = 100000;
    const ll MOD = 1'000'000'007;

    vector<ll> fibonacci(MAX_INDEX + 1);
    fibonacci[1] = 1;
    fibonacci[2] = 1;
    for (int i = 3; i <= MAX_INDEX; ++i) {
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % MOD;
    }

    int N, Q;
    cin >> N >> Q;

    vector<ll> prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int index;
        cin >> index;
        prefix[i] = (prefix[i - 1] + fibonacci[index]) % MOD;
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << (prefix[R] - prefix[L - 1] + MOD) % MOD << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}