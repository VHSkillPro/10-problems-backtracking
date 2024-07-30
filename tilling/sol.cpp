#include <bits/stdc++.h>
#define taskname "abc345_d"
using namespace std;

int n, h, w;
int a[7], b[7];
bool used[7], grid[10][10];

void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

bool canPlace(int x, int y, int h, int w) {
    if (x + h > ::h || y + w > ::w) return false;
    for (int i = x; i < x + h; ++i)
        for (int j = y; j < y + w; ++j)
            if (grid[i][j]) return false;
    return true;
}

void place(int x, int y, int h, int w, bool state) {
    for (int i = x; i < x + h; ++i)
        for (int j = y; j < y + w; ++j)
            grid[i][j] = state;
}

void backtrack(int i, int r, int c, bool &ans) {
    if (ans) {
        return ;
    }

    while (grid[r][c]) {
        r += (++c) / w;
        c %= w;
    }

    if (r >= h) {
        ans = true;
        return ;
    }

    for (int j = 0; j < n; ++j) {
        if (used[j]) continue;

        if (canPlace(r, c, a[j], b[j])) {
            used[j] = true;
            place(r, c, a[j], b[j], true);

            backtrack(i + 1, r, c, ans);

            used[j] = false;
            place(r, c, a[j], b[j], false);
        }

        if (a[j] != b[j] && canPlace(r, c, b[j], a[j])) {
            used[j] = true;
            place(r, c, b[j], a[j], true);

            backtrack(i + 1, r, c, ans);

            used[j] = false;
            place(r, c, b[j], a[j], false);
        }
    }
}

void Solve() {
    cin >> n >> h >> w;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    bool ans = false;
    backtrack(0, 0, 0, ans);

    cout << (ans ? "Yes" : "No");
}

int main(){
    Input();
    Solve();
    return 0;
}