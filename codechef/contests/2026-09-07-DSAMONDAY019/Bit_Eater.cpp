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
    cin >> N;

    vector<int> A(N);
    for (int &value : A) {
        cin >> value;
    }

    int M;
    cin >> M;

    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << (A[i] >> M);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}