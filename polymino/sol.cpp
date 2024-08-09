#include <bits/stdc++.h>
#define taskname "abc211_e"
using namespace std;

typedef unsigned long long ll;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

void Solve() {
    int n, k; cin >> n >> k;
    vector<string> board(n);
    for (string &row: board) cin >> row;

    int ans = 0;
    map<ll, bool> isVisited;

    auto isInside = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    };

    function<void(int, ll)> dfs = [&](int cnt, ll state) {
        if (isVisited[state]) return ;
        isVisited[state] = true;

        if (cnt == k + 1) {
            ++ans;
            return ;
        }

        vector<pair<int, int>> nxt;
        for (int r = 0; r < n; ++r) 
            for (int c = 0; c < n; ++c) {
                if (board[r][c] != '.') continue;

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if (isInside(nr, nc) && board[nr][nc] == '@') {
                        nxt.push_back({r, c});
                        break;
                    }
                }
            }
        
        for (auto [r, c]: nxt) {
            board[r][c] = '@';
            dfs(cnt + 1, state | (1ll << (r * n + c)));
            board[r][c] = '.';
        }
    };

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            if (board[i][j] == '.') {
                board[i][j] = '@';
                dfs(2, 1ull << (i * n + j));
                board[i][j] = '.';   
            }

    cout << ans;
}

int main(){
    Input();
    Solve();
    return 0;
}