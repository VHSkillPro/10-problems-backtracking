#include <bits/stdc++.h>
#define taskname "sol"
using namespace std;

int n, a, b, c;
int l[8];

void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int dfs(int i, int A, int B, int C) {
    if (i == n) {
        if (A == 0 || B == 0 || C == 0) return 1e9;
        return abs(a - A) + abs(b - B) + abs(c - C) - 30;
    }
    int ans1 = dfs(i + 1, A, B, C);
    int ans2 = dfs(i + 1, A + l[i], B, C) + 10;
    int ans3 = dfs(i + 1, A, B + l[i], C) + 10;
    int ans4 = dfs(i + 1, A, B, C + l[i]) + 10;
    return min({ans1, ans2, ans3, ans4});
}

void Solve() {
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++) cin >> l[i];
    cout << dfs(0, 0, 0, 0) << "\n";
}

int main(){
    Input();
    Solve();
    return 0;
}