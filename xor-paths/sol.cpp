#include <bits/stdc++.h>
#define taskname "F"
using namespace std;
 
typedef long long ll;
 
void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
int get(int mask, int k) {
    return mask >> k & 1;
}
 
void Solve() {
    int n, m; cin >> n >> m;
    ll k; cin >> k;
 
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
 
    map<ll, int> cnt[21][21];
    function<void(int, int, ll)> back_track = [&](int x, int y, ll val) {
        val ^= a[x][y];
        if (x + y == m + 1) {
            cnt[x][y][val]++;
            return ;
        }
        if (x + 1 <= n) back_track(x + 1, y, val);
        if (y + 1 <= m) back_track(x, y + 1, val);
    };
    back_track(1, 1, 0);
 
    ll ans = 0;
    back_track = [&](int x, int y, ll val) {
        val ^= a[x][y];
        if (x + y == m + 1) {
            ans += cnt[x][y][val ^ a[x][y]];
            return ;
        }
        if (x - 1 > 0) back_track(x - 1, y, val);
        if (y - 1 > 0) back_track(x, y - 1, val);
    };
    back_track(n, m, k);
 
    cout << ans;
}
 
int main(int argc, char* argv[]) {
    clock_t begin = clock();
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }
    Input();
    Solve();
    cerr << "Time: " << (clock() - begin + 1.0) / CLOCKS_PER_SEC << "s";
    return 0;
}