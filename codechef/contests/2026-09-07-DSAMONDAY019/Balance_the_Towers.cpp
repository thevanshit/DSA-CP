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

    vector<ll> A(N);
    for (ll &height : A) {
        cin >> height;
    }
    sort(A.begin(), A.end());

    ll answer = A.back() - A.front();
    for (int plusCount = 0; plusCount <= N; ++plusCount) {
        if (plusCount < N && A[plusCount] < K) {
            continue;
        }

        ll minimum = LLONG_MAX;
        ll maximum = LLONG_MIN;

        if (plusCount > 0) {
            minimum = min(minimum, A[0] + K);
            maximum = max(maximum, A[plusCount - 1] + K);
        }
        if (plusCount < N) {
            minimum = min(minimum, A[plusCount] - K);
            maximum = max(maximum, A[N - 1] - K);
        }

        answer = min(answer, maximum - minimum);
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}