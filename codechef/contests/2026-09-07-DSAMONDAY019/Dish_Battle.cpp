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

    vector<int> score(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> score[i];
    }

    vector<int> parent(N + 1), maximumScore = score;
    iota(parent.begin(), parent.end(), 0);

    auto find = [&](auto &&self, int chef) -> int {
        if (parent[chef] == chef) {
            return chef;
        }
        return parent[chef] = self(self, parent[chef]);
    };

    int Q;
    cin >> Q;
    while (Q--) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            cout << find(find, x) << '\n';
            continue;
        }

        int y;
        cin >> y;
        int firstChef = find(find, x);
        int secondChef = find(find, y);

        if (firstChef == secondChef) {
            cout << "Invalid query!" << '\n';
            continue;
        }

        if (maximumScore[firstChef] == maximumScore[secondChef]) {
            continue;
        }

        if (maximumScore[firstChef] < maximumScore[secondChef]) {
            swap(firstChef, secondChef);
        }
        parent[secondChef] = firstChef;
        maximumScore[firstChef] = max(maximumScore[firstChef],
                                     maximumScore[secondChef]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}