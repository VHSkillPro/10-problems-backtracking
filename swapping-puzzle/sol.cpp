#include <bits/stdc++.h>
using namespace std;

void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

void Solve() {
    int h, w; cin >> h >> w;
    int a[6][6], b[6][6];
    
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cin >> b[i][j];

    int p[6], q[6];
    for (int i = 1; i <= h; ++i) p[i] = i;
    for (int i = 1; i <= w; ++i) q[i] = i;

    int ans = 1e9;
    do {
        do {
            bool possible = true;
            for (int i = 1; i <= h; ++i)
                for (int j = 1; j <= w; ++j)
                    if (a[p[i]][q[j]] != b[i][j]) {
                        possible = false;
                        break;
                    }

            if (possible) {
                int cnt = 0;

                for (int i = 1; i <= h; ++i)
                    for (int j = 1; j < i; ++j)
                        if (p[j] > p[i]) ++cnt;
                
                for (int i = 1; i <= w; ++i)
                    for (int j = 1; j < i; ++j)
                        if (q[j] > q[i]) ++cnt;

                ans = min(ans, cnt);
            }
        }
        while (next_permutation(q + 1, q + w + 1));
    }
    while (next_permutation(p + 1, p + h + 1));

    cout << (ans != 1e9 ? ans : -1) << "\n";
}

int main(){
    Input();
    Solve();
    return 0;
}