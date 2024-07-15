#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, T; cin >> n >> T;
    vector<int> s(n);
    for (int &val: s) cin >> val;
    sort(s.rbegin(), s.rend());

    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
        suff[i] = suff[i + 1] + s[i];

    ll ans = 0, cnt = 0;
    function<void(int, int, int)> backtrack = [&](int i, int sum, int state) {
        for (int c = 0; c < 2; ++c) {
            int next_sum = sum + c * s[i];
            int next_state = state + c * (1 << i);
            if (next_sum > T || next_sum + suff[i + 1] < T) continue;
            
            if (i == n - 1) {
                if (next_sum == T) {
                    ans += next_state;
                    ++cnt;
                }
            }
            else backtrack(i + 1, next_sum, next_state);
        }
    };
    backtrack(0, 0, 0);

    cout << cnt << " " << ans << "\n";
    return 0;
}