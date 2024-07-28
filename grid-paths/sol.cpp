#include <bits/stdc++.h>
using namespace std;
 
const short dx[] = {-1, 0, 1, 0};
const short dy[] = {0, 1, 0, -1};
 
string path;
int ans = 0;
bool visited[9][9];
 
void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
void backtrack(int x, int y, int i) {
    if (i == path.size()) {
        if (x == 7 && y == 1) ++ans;
        return ;
    }
 
    if (x == 7 && y == 1) return ;
    if (!visited[x][y - 1] && !visited[x][y + 1] && (visited[x - 1][y] && visited[x + 1][y])) return ;
    if (!visited[x - 1][y] && !visited[x + 1][y] && (visited[x][y - 1] && visited[x][y + 1])) return ;
 
    if (path[i] != '?') {
        int n_x = x, n_y = y;
        switch (path[i]) {
            case 'U': --n_x; break;
            case 'D': ++n_x; break;
            case 'L': --n_y; break;
            case 'R': ++n_y; break;
        }
 
        if (!visited[n_x][n_y]) {
            visited[n_x][n_y] = true;
            backtrack(n_x, n_y, i + 1);
            visited[n_x][n_y] = false;
        }
    }
    else {
        int n_x, n_y;
        for (int j = 0; j < 4; ++j) {
            n_x = x + dx[j], n_y = y + dy[j];
            if (!visited[n_x][n_y]) {
                visited[n_x][n_y] = true;
                backtrack(n_x, n_y, i + 1);
                visited[n_x][n_y] = false;
            }
        }
    }
};
 
void Solve() {
    cin >> path;
 
    for (int i = 0; i < 9; ++i) {
        visited[0][i] = visited[8][i] = true;
        visited[i][0] = visited[i][8] = true;
    }
 
    visited[1][1] = true;
    backtrack(1, 1, 0);
 
    cout << ans;
}
 
int main(){
    Input();
    Solve();
    return 0;
}